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


#ifndef COMMON_H
#define COMMON_H


#include <string>
//#include <memory>

#define QUICK_PROP_STR(name, setter) private: std::string _##name; public: std::string name () const { return _##name; } void setter (const std::string& v) { _##name = v; }


#define QUICK_PROPERTY(id, setter, type) \
    private: \
        type  _##id; \
    public: \
        type id () const { return _##id; } \
        void setter (const type & v) { _##id = v; }

typedef std::string std_str;


#endif