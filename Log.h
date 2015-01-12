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


#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>


class Log {

  public:
    const std::string LTYPE_CLIENT = "client";
    const std::string LTYPE_DRIVER = "driver";
    const std::string LTYPE_BROWSER = "browser";
    const std::string LTYPE_SERVER = "server";

    int timestamp;
    std::string level;
    std::string message;
    void print();

};

#endif




