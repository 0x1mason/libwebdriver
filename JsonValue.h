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


#ifndef JSONVALUE_H
#define	JSONVALUE_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <assert.h>
class JsonValue;

typedef std::map<std::string, JsonValue> JsonObject;
typedef std::vector<JsonValue> JsonArray;

enum ValType {
    Empty = 0,
    Bool,
    Int,
    String,
    Object,
    Array
};

class JsonValue
{
    class ObjectPtr; // pimpl 
    
public:
    ~JsonValue(){};
    explicit JsonValue();
    JsonValue(bool val);
    JsonValue(int val);
    JsonValue(const std::string& val);
    JsonValue(const JsonObject& val);
    JsonValue(const JsonArray& val);
    JsonValue(const char* str);
    JsonValue(std::shared_ptr<ObjectPtr> obj);
    JsonValue(const JsonValue& other);
    
    int asInt() const;
    bool asBool() const;
    std::string asStr() const;
    ::JsonObject& asObject();
    ::JsonArray& asArray();
    
    bool isEmptyOrNull() const;
    const ValType type() const { return _type; };
    std::string stringify() const;
    
    JsonValue& operator[](const std::string& key);
    const JsonValue& operator[](const std::string& key) const;
    
    static std::unique_ptr<JsonValue> create2(const std::string &json);
    static JsonValue create(const std::string &json);
    static std::string stringify(const JsonObject& obj);
    static std::string stringify(const JsonArray& array);
    
    JsonValue& operator=(const JsonValue& other);
    JsonValue& operator=(JsonValue&& other);

private:
    std::shared_ptr<ObjectPtr> _object;   
    
    ValType _type;
    bool _boolVal = false;
    int _intVal = -1;
    std::string _strVal;
    ::JsonArray _jArray;
    ::JsonObject _jObject;
};

#endif	/* JSONVALUE_H */

