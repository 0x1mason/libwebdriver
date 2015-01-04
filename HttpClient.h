#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

//#include "jsonengine.hpp"

#include "JsonValue.h"
#include "Response.h"
#include <map>


typedef std::map<std::string, int> StatusMap;

namespace HttpClient
{
    int getStatus(const std::string&);

    std::unique_ptr<Response> get(const std::string&);
    std::unique_ptr<Response> post(const std::string&,
                                   const std::string& = "");
    std::unique_ptr<Response> post(const std::string&,
                                   const JsonObject&);
    std::unique_ptr<Response> del(const std::string&);
    
    static StatusMap statusmap;
};

#endif
