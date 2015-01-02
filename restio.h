#ifndef RESTIO_H
#define RESTIO_H

//#include "jsonengine.hpp"

#include "JsonValue.h"
#include "Response.h"
#include <map>
#include <memory>


typedef std::map<std::string, int> StatusMap;

namespace restio
{
   // std::string doSession2(const std::string& url, const std::string& verb, const std::string& data);
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
