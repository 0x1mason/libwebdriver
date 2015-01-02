
#include "Utils.h"
#include "Entity.h"



bool Entity::equals(const Entity &other) const
{
    return id() == other.id() && serverUrl() == other.serverUrl();
}


void Entity::setServerUrl(const std::string &host)
{   
    if (host.substr(0, 7) != "http://") {
        _serverUrl = "http://" + host;
    }
    else {
        _serverUrl = host;
    }
}


std::string Entity::makeUrl(const std::string& path)
{
    return serverUrl() + path;
}


bool SessionEntity::equals(const SessionEntity &other) const
{
    return session()->equals(*other.session()) && Entity::equals(other);
}


std::string SessionEntity::makeUrl(const std::string& path)
{
    std::string formattedPath = ::sreplace(path, "{0}", session()->id());
    formattedPath = ::sreplace(formattedPath, "{1}", id());
    
    return Entity::makeUrl(formattedPath);
}
