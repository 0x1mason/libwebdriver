#ifndef ENTITY_H
#define ENTITY_H



#include "Common.h"


class Entity
{
public:
    Entity(){};
    // unfortunately, can't make this protected because of template in SessionEntity ctor
    Entity(const std::string &id, const std::string &host)
        : _id(id) { setServerUrl(host); };
    std::string id() const { return _id; }
    std:: string serverUrl() const { return _serverUrl; }
    bool equals(const Entity& other) const;
    
protected:
    virtual std::string makeUrl(const std::string& path);
    void setServerUrl(const std::string &host);
    
private:
    std::string _id;
    std::string _serverUrl;
};


class SessionEntity: public Entity
{
public:
    SessionEntity(): Entity("","") {};
    SessionEntity(SessionEntity&& other): Entity::Entity(other.id(), other.serverUrl()), _session(other._session) {}
    SessionEntity(const std::string &id, std::shared_ptr<Entity> session)
    : Entity(id, session->serverUrl()), _session(session) {};
    bool equals(const SessionEntity& other) const;
    std::shared_ptr<Entity> session() const { return _session; }
    
protected:

    virtual std::string makeUrl(const std::string& path) override;
    
private:
    std::shared_ptr<Entity> _session;
};


#endif