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


#include <string>
#include <map>
#include <vector>

#include "Window.h"
#include "Log.h"
#include "Entity.h"
#include "Status.h"

#include "JsonValue.h"


class Session;

typedef std::vector<Log> Logs;
typedef std::vector<Session> Sessions;
typedef JsonObject Capabilities;

class Session: public Entity
{
  public:
    Session(const std::string& id, const std::string& host, const Capabilities& caps)
        : Entity::Entity(id, host), _capabilities(caps) {}
    
//    Session(const Session& other)
//        : Entity::Entity(other.id(), other.serverUrl()), _capabilities(other._capabilities) { }

    Window focusedWindow();
    Windows windows();
    Logs logs(const std::string& logType);
    
    static Session create(const std::string &host,
                          const Capabilities& desiredCapabilities);
    static Status status(const std::string &host);
    static Sessions sessions(const std::string &host);
    
protected:
        using Entity::Entity;

private:
    Capabilities _capabilities;
};

