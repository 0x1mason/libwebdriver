#include "Response.h"
#include "Session.h"
#include "HttpClient.h"
#include "Routes.h"
#include "make_unique.h"
#include "JsonValue.h"

using namespace Routes;


Window Session::focusedWindow()
{
    auto response = HttpClient::get(makeUrl(CONTEXT_WINDOW_HANDLE));
    
    return Window(response->sessionId(), std::make_shared<Session>(*this));
}


Windows Session::windows()
{
    auto response = HttpClient::get(makeUrl(CONTEXT_WINDOW_HANDLES));
    
    Windows windows;
    
    for (auto& win : response->value().asArray()) {
        Window w(win.asStr(), std::make_shared<Session>(*this));
        windows.push_back(std::move(w));
    }
    
    return windows;
}


// static non-member
std::string makeStaticUrl(const std::string& host, const std::string& path)
{
    std::string serverUrl = host + path;
    
    if (host.substr(0, 7) != "http://") {
        serverUrl = "http://" + serverUrl;
    }
    
    return serverUrl;
}


// static
Session Session::create(const std::string &host, const JsonObject& desiredCapabilities)
{
    std::string serverUrl = makeStaticUrl(host, SESSION);
    auto ans = HttpClient::post(serverUrl, {{"desiredCapabilities", desiredCapabilities}});
    
    return Session(ans->sessionId(), serverUrl, desiredCapabilities);
}


// static
Status Session::status(const std::string &host)
{
    std::string serverUrl = makeStaticUrl(host, STATUS);
    auto ans = HttpClient::get(serverUrl);
    
    if ( ans->status() != HttpClient::getStatus("Success")) {
        throw;
    }

    return { ans->value()["build"].asObject(), ans->value()["os"].asObject() };
}


// static
Sessions Session::sessions(const std::string &host)
{
    std::string serverUrl = makeStaticUrl(host, SESSIONS);
    auto ans = HttpClient::get(serverUrl);

    auto sessionArray = ans->value().asArray();
    Sessions sessions;
    
    // each session obj == {id:string, capabilities:obj}
    for (auto& s : sessionArray) {
        Capabilities caps = s["capabilities"].asObject();
        sessions.push_back(Session(s["sessionId"].asStr(), host, caps));
    }
    
    return sessions;
}