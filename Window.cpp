/* 
 * File:   Window.cpp
 * Author: saucelabs
 * 
 * Created on December 23, 2014, 2:40 PM
 */

#include "Window.h"
#include "Routes.h"
#include "restio.h"
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
    auto response = restio::get(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
    
    return { response->value()["x"].asInt(), response->value()["y"].asInt() };
}


std::pair<int, int> Window::size()
{
    auto url = makeUrl(Routes::WINDOW_SIZE);
    auto response = restio::get(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
    
    return { response->value()["width"].asInt(), response->value()["height"].asInt() };
}


void Window::setPosition(int x, int y)
{
    auto url = makeUrl(Routes::WINDOW_POSITION);
    auto response = restio::post(url, {{"x", x}, {"y", y}});
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


void Window::setSize(int width, int height)
{
    auto url = makeUrl(Routes::WINDOW_SIZE);
    auto response = restio::post(url, {{"width", width}, {"height", height}});
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


void Window::maximize()
{
    auto url = makeUrl(Routes::WINDOW_MAXIMIZE);
    auto response = restio::post(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


void Window::acceptAlert()
{
    auto url = makeUrl(Routes::CONTEXT_ACCEPT_ALERT);
    auto response = restio::post(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


void Window::dismissAlert()
{
    auto url = makeUrl(Routes::CONTEXT_DISMISS_ALERT);
    auto response = restio::post(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


std::string Window::alertText()
{
    auto url = makeUrl(Routes::CONTEXT_ALERT_TEXT);
    auto response = restio::get(url);
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
    
    return response->value().asStr();
}


void Window::sendKeysToAlert(const std::string& keys)
{
    auto url = makeUrl(Routes::CONTEXT_ALERT_TEXT);
    auto response = restio::post(url, {{"text", keys}});
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
}


void Window::_buttonAction(const MouseButton& btn, const std::string& url)
{
    auto response = restio::post(url, {{"button", btn}});
    
    if (response->status() != restio::getStatus("Success")) {
        throw;
    }
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


