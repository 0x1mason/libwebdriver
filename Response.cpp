/* 
 * File:   Response.cpp
 * Author: saucelabs
 * 
 * Created on December 22, 2014, 2:40 PM
 */

#include "Response.h"
#include <assert.h>
#include <iostream>


Response::Response(const std::string& responseBody, int httpStatus, const std::string& reason) : _raw(responseBody), _json(JsonValue::create(responseBody))
{
}


//const std::shared_ptr<JsonValue> Response::json() const
//{
//    return nullptr;
//}


int Response::status()
{
    if( _json.isEmptyOrNull() ||
        _json.type() != ValType::Object) {
        return -1;
    }
    
    return _json.asObject()["status"].asInt();
}


std::string Response::sessionId()
{
    if( _json.isEmptyOrNull() ||
       _json.type() != ValType::Object) {
        return "";
    }
    
    return _json.asObject()["sessionId"].asStr();
}


JsonValue& Response::value()
{
    return _json;
}