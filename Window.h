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


#ifndef WINDOW_H
#define	WINDOW_H

#include <vector>
#include <memory>

#include "Element.h"
#include "Cookie.h"
#include "JsonValue.h"

using std::vector;
using std::map;

//struct By {
//  static const std::string Css = "css selector";
//  static const std::string Name = "class name";
//    static const std::string LinkText = "link text";
//    static const std::string PartialLinkText = "partial link text";
//    static const std::string Tag = "tag name";
//    static const std::string XPath = "xpath";
//    static const std::string AccessibilityId;
//}

enum MouseButton
{
    LEFT = 0, MIDDLE = 1 , RIGHT = 2
};

class Window;
typedef std::vector<Window> Windows;



class Window: public SessionEntity
{
public:

    using SessionEntity::SessionEntity;

    std::pair<int, int> position(); // x, y
    std::pair<int, int> size(); // w, h
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void maximize();


    void go(const std::string& url);
    void back();
    void forward();
    void refresh();

    void focus();
    std::string screenshot();
    std::string url();
    std::string source();

    Cookies cookies();
    void createCookie(const Cookie&);
    void deleteCookie(const std::string&);

    Element element(const std::string& by, const std::string& value);
    Elements elements(const std::string& by, const std::string& value);
    Element focusedElement();

    //void click(Element, int x_offset = 0, int y_offset = 0);
    //void click(const MouseButton& btn = MouseButton::LEFT);
    void buttonDown(const MouseButton& btn = MouseButton::LEFT);
    void buttonUp(const MouseButton& btn = MouseButton::LEFT);
    void buttonClick(const MouseButton& btn = MouseButton::LEFT);
    void buttonDblClick(const MouseButton& btn = MouseButton::LEFT);
    
    JsonValue execute(const std::string&, bool);

  	/* Alerts/Notices Management */
    void acceptAlert();
    void dismissAlert();
    std::string alertText();
    void sendKeysToAlert(const std::string&);
    
private:
    void _buttonAction(const MouseButton& btn, const std::string& url);
};
#endif	/* WINDOW_H */

