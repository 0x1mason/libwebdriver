/* 
 * File:   Window.h
 * Author: saucelabs
 *
 * Created on December 23, 2014, 2:40 PM
 */

#ifndef WINDOW_H
#define	WINDOW_H

//class Window {
//public:
//    Window();
//    Window(const Window& orig);
//    virtual ~Window();
//private:
//
//};
#include <vector>
#include <memory>

#include "Element.h"
#include "Cookie.h"
#include "JsonValue.h"

using std::vector;
using std::map;

//struct By {
//  static const std::string Css;
//  static const std::string Name;
//    static const std::string LinkText;
//    static const std::string PartialLinkText;
//    static const std::string Tag;
//    static const std::string XPath;
//    static const std::string AccessibilityId;
//}

enum MouseButton
{
    LEFT = 0, MIDDLE = 1 , RIGHT = 2
};

class Window;
typedef std::vector< Window> Windows;
typedef std::vector< Cookie> Cookies;
typedef std::vector<Element> Elements;

class Window: public SessionEntity {
public:
   // Window() : SessionEntity::SessionEntity() {};
    using SessionEntity::SessionEntity;

    std::pair<int, int> position(); // x, y
    std::pair<int, int> size(); // w, h
    void setPosition(int x, int y); // x, y
    void setSize(int, int); // w, h
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

    //void click(std::unique_ptr<Element>, int x_offset = 0, int y_offset = 0);
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

