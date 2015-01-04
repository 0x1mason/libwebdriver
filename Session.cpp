#include "Response.h"
#include "Session.h"
#include "restio.h"
#include "Routes.h"
#include "make_unique.h"
#include "JsonValue.h"

using namespace Routes;


Window Session::focusedWindow()
{
    auto response = restio::get(makeUrl(CONTEXT_WINDOW_HANDLE));
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
    
    return Window(response->sessionId(), std::make_shared<Session>(*this));
}


Windows Session::windows()
{
    auto response = restio::get(makeUrl(CONTEXT_WINDOW_HANDLES));
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
    
    Windows windows;// = std::make_unique<Windows>();
    
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
std::shared_ptr<Session> Session::create(const std::string &host, const JsonObject& desiredCapabilities)
{
    std::string serverUrl = makeStaticUrl(host, SESSION);
    auto ans = restio::post(serverUrl, {{"desiredCapabilities", desiredCapabilities}});

    if ( ans->status() != restio::getStatus("Success")) {
        throw;
    }
    
    return std::make_shared<Session>(ans->sessionId(), serverUrl, desiredCapabilities);
}


// static
Status Session::status(const std::string &host)
{
    std::string serverUrl = makeStaticUrl(host, STATUS);
    auto ans = restio::get(serverUrl);
    
    if ( ans->status() != restio::getStatus("Success")) {
        throw;
    }

    return { ans->value()["build"].asObject(), ans->value()["os"].asObject() };
}


// static
std::unique_ptr<Sessions> Session::sessions(const std::string &host)
{
    std::string serverUrl = makeStaticUrl(host, SESSIONS);
    auto ans = restio::get(serverUrl);
    
    if ( ans->status() != restio::getStatus("Success")) {
        throw;
    }
    
    auto sessionArray = ans->value().asArray();
    auto sessions = std::make_unique<Sessions>();
    
    // each session obj == {id:string, capabilities:obj}
    for (auto& s : sessionArray) {
        Capabilities caps = s["capabilities"].asObject();
        auto o = std::make_shared<Session>(s["sessionId"].asStr(), host, caps);
        sessions->push_back(o);
    }
    
    return sessions;
}