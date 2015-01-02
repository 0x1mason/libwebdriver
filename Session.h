#include <string>
#include <map>
#include <vector>

#include "Window.h"
#include "Log.h"
#include "Entity.h"
#include "Status.h"

#include "JsonValue.h"


//struct By {
//  static const std::string Css;
//  static const std::string Name;
//    static const std::string LinkText;
//    static const std::string PartialLinkText;
//    static const std::string Tag;
//    static const std::string XPath;
//    static const std::string AccessibilityId;
//}

class Session;

typedef std::vector< std::shared_ptr<Log> > Logs;
typedef std::vector< std::shared_ptr<Session> > Sessions;
typedef JsonObject Capabilities;

class Session: public Entity
{
  public:
    Session(const std::string& id, const std::string& host, const Capabilities& caps)
        : Entity::Entity(id, host), _capabilities(caps) {}
    
//    Session(const Session& other)
//        : Entity::Entity(other.id(), other.serverUrl()), _capabilities(other._capabilities) { }

    std::unique_ptr<Window> focusedWindow();
    std::unique_ptr<Windows> windows();
    std::unique_ptr<Logs> logs(const std::string& logType);
    
    static std::shared_ptr<Session> createSession(const std::string &host,
                                                  const Capabilities& desiredCapabilities);
    static Status status(const std::string &host);
    static std::unique_ptr<Sessions> sessions(const std::string &host);
    
protected:
        using Entity::Entity;

private:
    Capabilities _capabilities;
};

