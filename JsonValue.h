/* 
 * File:   JsonValue.h
 * Author: saucelabs
 *
 * Created on December 23, 2014, 11:57 AM
 */

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
    explicit JsonValue();
    JsonValue(bool val);
    JsonValue(int val);
    JsonValue(const std::string& val);
    JsonValue(const JsonObject& val);
    JsonValue(const JsonArray& val);
    JsonValue(const char* str);
    JsonValue(std::shared_ptr<ObjectPtr> obj);
    //JsonValue(const JsonValue& other);
    //JsonValue(JsonValue&& other);
    
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
    
        static JsonValue create2(const std::string &json);
    static std::unique_ptr<JsonValue> create(const std::string &json);
    static std::string stringify(const JsonObject& obj);
    static std::string stringify(const JsonArray& array);
    
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

