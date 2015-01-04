/* 
 * File:   Response.h
 * Author: saucelabs
 *
 * Created on December 22, 2014, 2:40 PM
 */

#ifndef RESPONSE_H
#define	RESPONSE_H


//#include "Common.h"
#include <string>
#include "JsonValue.h"

class Response
{
public:
    Response(const std::string& responseBody, int httpStatus, const std::string& reason);

    int status();
    std::string sessionId();
    JsonValue& value();
    std::string raw() const;
    //const std::shared_ptr<JsonValue> json() const;

private:
    JsonValue _json;
    std::string _raw;
};



#endif	/* RESPONSE_H */

