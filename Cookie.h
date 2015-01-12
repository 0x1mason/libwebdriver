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


#ifndef COOKIE_HPP
#define COOKIE_HPP

#include <string>
#include <vector>
#include "Common.h"


class Cookie;
typedef std::vector<Cookie> Cookies;

struct Cookie
{
    QUICK_PROPERTY(name, setName, std::string);
    QUICK_PROPERTY(value, setValue, std::string);
    QUICK_PROPERTY(path, setPath, std::string);
    QUICK_PROPERTY(domain, setDomain, std::string);
    QUICK_PROPERTY(secure, setSecure, bool);
    QUICK_PROPERTY(httpOnly, setHttpOnly, bool);
    QUICK_PROPERTY(expiry, setExpiry, int);
    
  public:
    Cookie(const std::string& name,
           const std::string& value,
           const std::string& path = "",
           const std::string& domain = "",
           int expiry = 0, // no expiry
           bool secure = false,
           bool httpOnly = false)
    {
        setName(name);
        setValue(value);
        setPath(path);
        setDomain(domain);
        setExpiry(expiry);
        setSecure(secure);
        setHttpOnly(httpOnly);
    }
    
    bool operator == (const Cookie& c) const
    {
        return name() == c.name() &&
               value() == c.value() &&
               path() == c.path() &&
               domain() == c.domain() &&
               secure() == c.secure() &&
               httpOnly() == c.httpOnly() &&
               expiry() == c.expiry();
    }
};
#endif