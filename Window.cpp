/* 
 * File:   Window.cpp
 * Author: saucelabs
 * 
 * Created on December 23, 2014, 2:40 PM
 */

#include "Window.h"
#include "Routes.h"
#include "HttpClient.h"
//Window::Window() {
//}
//
//Window::Window(const Window& orig) {
//}
//
//Window::~Window() {
//}

std::pair<int, int> Window::position()
{
    auto url = makeUrl(Routes::WINDOW_POSITION);
    auto response = HttpClient::get(url);
    
    return { response->value()["x"].asInt(), response->value()["y"].asInt() };
}


std::pair<int, int> Window::size()
{
    auto url = makeUrl(Routes::WINDOW_SIZE);
    auto response = HttpClient::get(url);
    
    return { response->value()["width"].asInt(), response->value()["height"].asInt() };
}


void Window::setPosition(int x, int y)
{
    auto url = makeUrl(Routes::WINDOW_POSITION);
    HttpClient::post(url, {{"x", x}, {"y", y}});
}


void Window::setSize(int width, int height)
{
    auto url = makeUrl(Routes::WINDOW_SIZE);
    HttpClient::post(url, {{"width", width}, {"height", height}});
}


void Window::maximize()
{
    auto url = makeUrl(Routes::WINDOW_MAXIMIZE);
    HttpClient::post(url);
}


void Window::acceptAlert()
{
    auto url = makeUrl(Routes::CONTEXT_ACCEPT_ALERT);
    HttpClient::post(url);
}


void Window::dismissAlert()
{
    auto url = makeUrl(Routes::CONTEXT_DISMISS_ALERT);
    HttpClient::post(url);
}


std::string Window::alertText()
{
    auto url = makeUrl(Routes::CONTEXT_ALERT_TEXT);
    auto response = HttpClient::get(url);
    
    return response->value().asStr();
}


void Window::sendKeysToAlert(const std::string& keys)
{
    auto url = makeUrl(Routes::CONTEXT_ALERT_TEXT);
    HttpClient::post(url, {{"text", keys}});
}


void Window::_buttonAction(const MouseButton& btn, const std::string& url)
{
    HttpClient::post(url, {{"button", btn}});
}


void Window::buttonDown(const MouseButton& btn)
{
    _buttonAction(btn, makeUrl(Routes::CONTEXT_BUTTONDOWN));
}


void Window::buttonUp(const MouseButton& btn)
{
    _buttonAction(btn, makeUrl(Routes::CONTEXT_BUTTONUP));
}


void Window::buttonClick(const MouseButton& btn)
{
    _buttonAction(btn, makeUrl(Routes::CONTEXT_CLICK));
}


void Window::buttonDblClick(const MouseButton& btn)
{
    _buttonAction(btn, makeUrl(Routes::CONTEXT_DOUBLECLICK ));
}


