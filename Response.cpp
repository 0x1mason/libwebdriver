/* 
 * File:   Response.cpp
 * Author: saucelabs
 * 
 * Created on December 22, 2014, 2:40 PM
 */



#include "Response.h"
#include <assert.h>
#include <iostream>

Response::Response(const std::string& responseBody, int httpStatus, const std::string& reason) : _raw(responseBody), _json(std::move(JsonValue::create(responseBody)))
{
    std::cout << "Response received: " << responseBody << "\r\n";
//    if (!responseBody.empty()) {
//        _raw = responseBody;
//        _json = std::move(JsonValue::create(_raw));
//        assert(_json->type() == ValType::Object); // top-lvl should always be object in JSONWP
//    }
}

const std::shared_ptr<JsonValue> Response::json() const
{
    return nullptr;
    //return std::move(_json);
}
    
int Response::status()
{
    if (_json->type() != ValType::Empty) {
//        auto jv(_json->asObject());
//        auto jv2(jv["status"]);
//        std::cout << jv2.stringify();
        return _json->asObject()["status"].asInt();
    }
    
    throw "Empty response";
}

std::string Response::sessionId()
{
    if( _json->isEmptyOrNull()) {
        return nullptr;
    }
    
    if (_json->type() != ValType::Empty) {
        return _json->asObject()["sessionId"].asStr();
    }
    
    throw "Empty response";
}


JsonValue& Response::value()
{
    if (_json->type() == ValType::Object) {
        return _json->asObject()["value"];
    }
    
    throw "Empty response";
}