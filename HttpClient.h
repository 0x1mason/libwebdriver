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


#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

//#include "jsonengine.hpp"

#include "JsonValue.h"
#include "Response.h"
#include <map>


typedef std::map<std::string, int> StatusMap;

namespace HttpClient
{
    int getStatus(const std::string&);

    //TODO: remove pointers
    std::unique_ptr<Response> get(const std::string& url);
    std::unique_ptr<Response> post(const std::string& url,
                                   const std::string& data = "");
    std::unique_ptr<Response> post(const std::string& url,
                                   const JsonObject& jsonData);
    std::unique_ptr<Response> del(const std::string& url);
    
    static StatusMap statusmap;
};

#endif
