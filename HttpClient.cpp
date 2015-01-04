#include "HttpClient.h"
#include "Response.h"
#include "JsonValue.h"
#include "Utils.h"
//#include "http.h"
#include "make_unique.h"
#include "Common.h"
#include "Routes.h"
#include <string>
#include <sstream>
#include <iostream>
#include <sstream>
#include <map>

#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
//#include "Poco/CountingStream.h"
//#include "Poco/Net/HTTPStream.h"
//#include "Poco/Net/HTTPHeaderStream.h"
//#include "Poco/Net/HTTPChunkedStream.h"
//#include "Poco/Net/HTTPFixedLengthStream.h"

#include "Exceptions.h"


namespace HttpClient {
    

    
    std::map<std::string, int> initSMAP() {
        
        std::map<std::string, int> smap;
        smap["Success"] = 0;
        smap["NoSuchDriver"] = 6;
        smap["NoSuchElement"] = 7;
        smap["NoSuchFrame"] = 8;
        smap["UnknownCommand"] = 9;
        smap["StaleElementReference"] = 10;
        smap["ElementNotVisible"] = 11;
        smap["InvalidElementState"] = 12;
        smap["UnknownError"] = 13;
        smap["ElementIsNotSelectable"] = 15;
        smap["JavaScriptError"] = 17;
        smap["XPathLookupError"] = 19;
        smap["Timeout"] = 21;
        smap["NoSuchWindow"] = 23;
        smap["InvalidCookieDomain"] = 24;
        smap["UnableToSetCookie"] = 25;
        smap["UnexpectedAlertOpen"] = 26;
        smap["NoAlertOpenError"] = 27;
        smap["ScriptTimeout"] = 28;
        smap["InvalidElementCoordinates"] = 29;
        smap["IMENotAvailable"] = 30;
        smap["IMEEngineActivationFailed"] = 31;
        smap["InvalidSelector"] = 32;
        smap["SessionNotCreatedException"] = 33;
        smap["MoveTargetOutOfBounds"] = 34;
        return smap;
    }
    
    
    std::unique_ptr<Response> doSession(const std::string& url, const std::string& verb, const std::string& data)
    {
       // testConnect();
        
        std::stringstream response;
        
        try {
            // prepare session
            Poco::URI uri(url);
            Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());

            // prepare path
            std::string path(uri.getPathAndQuery());
            if (path.empty()) path = "/";
            
            // send request
            Poco::Net::HTTPRequest req(verb, path, Poco::Net::HTTPMessage::HTTP_1_1);
            req.set("Content-Type", "application/json;charset=UTF-8");
            req.set("Accept", "application/json");
            
            if (!data.empty()) {
                req.setContentLength((int) data.length());
                session.sendRequest(req) << data;
            }
            else {
                session.sendRequest(req);
            }
            
            // get response
            Poco::Net::HTTPResponse res;
            std::istream &is = session.receiveResponse(res);
            Poco::StreamCopier::copyStream(is, response);
            
            // appium still responds with 303, requiring some contortions to get the session id
            if (url.find(Routes::SESSION) != std::string::npos
                && res.getStatus() == 303) {
                std::cout << response.str();

                // extract session id from Location header
                std::string path = res.get("Location");
                size_t i = path.find_last_of("/");
                std::string id = path.substr(i + 1);
                
                // now create a faux json response so we can continue using logic consistent with other WD servers
                response.clear();//clear any bits set
                response.str("{\"status\":0,\"value\":{},\"sessionId\":\"" + id + "\"}");

                
            }  // TODO: handle infinite loop for 300s
            else if (res.getStatus() > 399 && res.getStatus() < 500) {
                
                throw_ClientException(response.str());
            }
            else if (res.getStatus() > 499 && res.getStatus() < 600) {
                throw_RemoteException(response.str());
            }
            else {

            }
        }
        catch (Poco::Exception &ex) {
             std::cerr << ex.displayText() << std::endl;
        }
        
        return std::make_unique<Response>(response.str(), 0, "");
    }
    
    
    std::unique_ptr<Response> get(const std::string& url)
    {        
        return doSession(url, Poco::Net::HTTPRequest::HTTP_GET, "");
    }
    
    
    std::unique_ptr<Response> post(const std::string& url, const std::string& pdata)
    {
        return doSession(url, Poco::Net::HTTPRequest::HTTP_POST, pdata);
    }
    
    
    std::unique_ptr<Response> post(const std::string& url, const JsonObject& data)
    {
        return post(url, JsonValue::stringify(data));
    }

    
    std::unique_ptr<Response> del(const std::string& url)
    {
        return doSession(url, Poco::Net::HTTPRequest::HTTP_DELETE, "");
    }

    
    int getStatus(const std::string& key)
    {
        if (statusmap.empty()) {
            statusmap.insert(std::pair<std::string, int>("Success", 0));
//            statusmap["Success"] = 0;
//            statusmap["NoSuchDriver"] = 6;
//            statusmap["NoSuchElement"] = 7;
//            statusmap["NoSuchFrame"] = 8;
//            statusmap["UnknownCommand"] = 9;
//            statusmap["StaleElementReference"] = 10;
//            statusmap["ElementNotVisible"] = 11;
//            statusmap["InvalidElementState"] = 12;
//            statusmap["UnknownError"] = 13;
//            statusmap["ElementIsNotSelectable"] = 15;
//            statusmap["JavaScriptError"] = 17;
//            statusmap["XPathLookupError"] = 19;
//            statusmap["Timeout"] = 21;
//            statusmap["NoSuchWindow"] = 23;
//            statusmap["InvalidCookieDomain"] = 24;
//            statusmap["UnableToSetCookie"] = 25;
//            statusmap["UnexpectedAlertOpen"] = 26;
//            statusmap["NoAlertOpenError"] = 27;
//            statusmap["ScriptTimeout"] = 28;
//            statusmap["InvalidElementCoordinates"] = 29;
//            statusmap["IMENotAvailable"] = 30;
//            statusmap["IMEEngineActivationFailed"] = 31;
//            statusmap["InvalidSelector"] = 32;
//            statusmap["SessionNotCreatedException"] = 33;
//            statusmap["MoveTargetOutOfBounds"] = 34;
        }
        //
        return 0;
    }
};

