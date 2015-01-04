#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <sstream>


class LibWebDriverException: public std::runtime_error
{
public:
    LibWebDriverException(const std::string& msg, const std::string& fileName,
                          const std::string& func, int lineNum)
        : runtime_error::runtime_error(msg)
    {
        _msg << fileName << " " << func << " " << lineNum << ":\r\n" << msg;
    }
    
    
    virtual const char* what() const throw() override
    {
        return _msg.str().c_str();
    }
    
    
private:
    std::ostringstream _msg;
};


class RemoteException: public LibWebDriverException
{
public:
    using LibWebDriverException::LibWebDriverException;
};


class ClientException: public LibWebDriverException
{
public:
    using LibWebDriverException::LibWebDriverException;
};

#define throw_RemoteException(msg) throw RemoteException(msg, __FILE__, __func__, __LINE__)
#define throw_ClientException(msg) throw ClientException(msg, __FILE__, __func__, __LINE__)

#endif