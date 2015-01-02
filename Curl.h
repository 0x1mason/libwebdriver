#ifndef CURL_H
#define CURL_H

#include <curl/curl.h>
#include <stdlib.h>
#include <string>
#include <map>

class http {
    
private:
    CURL* ch;
    struct curl_slist *headers;
public:
    http();
    void destroy();
    void add_header(std::string);
    std::string get(std::string url);
    std::string post(std::string,std::string);
   // std::string post(std::string url, std::map<std::string, std::string> post_data);
    std::string del(std::string url);
    
};

#endif