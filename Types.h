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


#ifndef libwebdriver_Types_h
#define libwebdriver_Types_h

#include "Common.h"

namespace WebDriver
{
    typedef unsigned long long TimePoint;
    typedef unsigned Duration;
    
    struct Size
    {
        QUICK_PROPERTY(width, setWidth, int);
        QUICK_PROPERTY(height, setHeight, int);
        
        Size(int width, int height) { setWidth(width); setHeight(height); }
        Size() : Size(0, 0) {}
    };
    
    struct Point
    {
        QUICK_PROPERTY(x, setX, int);
        QUICK_PROPERTY(y, setY, int);
        
        Point(int x, int y) { setX(x); setY(y); }
        Point() : Point(0, 0) {};
    };
    
    typedef Point Offset;
    
    namespace Timeout
    {
        static const std::string Implicit = "implicit";
        static const std::string PageLoad = "page load";
        static const std::string Script = "script";
    } // namespace Timeout
    
    namespace By
    {
        static const std::string Css = "css selector";
        static const std::string Name = "class name";
        static const std::string LinkText = "link text";
        static const std::string PartialLinkText = "partial link text";
        static const std::string Tag = "tag name";
        static const std::string XPath = "xpath";
        static const std::string AccessibilityId;
    }
} // namespace WebDriver


#endif
