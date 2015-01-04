#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>


class Log {

  public:
    const std::string LTYPE_CLIENT = "client";
    const std::string LTYPE_DRIVER = "driver";
    const std::string LTYPE_BROWSER = "browser";
    const std::string LTYPE_SERVER = "server";

    int timestamp;
    std::string level;
    std::string message;
    void print();

};

#endif




