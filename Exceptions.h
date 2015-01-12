// Copyright 2015 Eric Millin
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


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