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


#ifndef ELEMENT_H
#define	ELEMENT_H

#include "Entity.h"
#include <memory>
#include <vector>

class Element;
typedef std::vector<Element> Elements;

class Element: public SessionEntity
{
public:
    using SessionEntity::SessionEntity;
    
    void click();
    void sendKey(int keynum);
    void sendKeys(const std::vector<int>&);
    void sendKeys(const std::string&);
    std::string text();
    std::string css(const std::string& property);
    std::string attribute(const std::string& attr);
    std::string name();

    Element clone_();
private:

};

#endif	/* ELEMENT_H */

