#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <osstream>


class RemoteException: public std::runtime_error
{
    
public:
    RemoteException(const std::string& msg, const std::string& fileName, int lineNum)
    {
        _msg << fileName << " " << lineNum << ": " << msg;
    }
    
    virtual const char* what() const override noexcept()
    {
        return _msg.str();
    }

private:
    std::ostringstream _msg;
    

    
} ;


#endif