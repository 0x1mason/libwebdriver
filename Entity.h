// Copyright 2015 Eric Millin
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef ENTITY_H
#define ENTITY_H



#include "Common.h"


class Entity
{
public:
    Entity(){};
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