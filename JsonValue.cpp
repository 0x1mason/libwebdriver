/* 
 * File:   JsonValue.cpp
 * Author: saucelabs
 * 
 * Created on December 23, 2014, 11:57 AM
 */

#include "JsonValue.h"
#include <string>
#include <assert.h>
#include <sstream>
#include "Poco/JSON/Array.h"
#include "Poco/JSON/Object.h"
#include "Poco/SharedPtr.h"
#include "Poco/JSON/Parser.h"
#include "Poco/Dynamic/Var.h"

#include "make_unique.h"


struct JsonValue::ObjectPtr
{
public:
    ObjectPtr(const ObjectPtr& other): valPtr(other.valPtr)
    {
       // std::cout << valPtr.toString();
    }
    
    ObjectPtr(const Poco::Dynamic::Var& val): valPtr(val)
    {
      //  std::cout << valPtr.toString();
    }

    ObjectPtr(const std::string& json)
    {
        Poco::JSON::Parser parser;
        valPtr = parser.parse(json);
    }

    Poco::Dynamic::Var valPtr;
    
    void toJsonObject(::JsonObject& jObj)
    {
        auto x = 5/0;
        std::cout << x;
        if (valPtr.isEmpty())
            return;
        
        Poco::JSON::Object::Ptr obj;
        
        try {
            obj = valPtr.extract<Poco::JSON::Object::Ptr>();
        }
        catch(Poco::BadCastException& ex) {
            std::cerr << __FILE__ << " " << __LINE__ << ": " << ex.displayText();
            return;
        }
        
        for (auto& kvp: *obj) {
            jObj.emplace(kvp.first, std::make_shared<ObjectPtr>(kvp.second));
        }
    }
    
    void toJsonArray(::JsonArray& jArray)
    {
        Poco::JSON::Array::Ptr jsonArray;
        
        try {
            jsonArray = valPtr.extract<Poco::JSON::Array::Ptr>();
        }
        catch(Poco::BadCastException& ex) {
            std::cerr << __FILE__ << " " << __LINE__ << ": " << ex.displayText();
            return;
        }
        
        for (auto& i: *jsonArray) {
            //auto o = std::make_shared<ObjectPtr>(i);
            JsonValue jv(std::make_shared<ObjectPtr>(i));
            jArray.push_back(jv);
        }
    }
};


JsonValue::JsonValue() : _type(ValType::Empty) {}


JsonValue::JsonValue(bool val) : _boolVal(val), _type(ValType::Bool) {}


JsonValue::JsonValue(int val) : _intVal(val), _type(ValType::Int) {}


JsonValue::JsonValue(const std::string& val) : _strVal(val), _type(ValType::String) {}


JsonValue::JsonValue(const char* val) : _strVal(val), _type(ValType::String) {}


JsonValue::JsonValue(const ::JsonObject& val) : _jObject(val), _type(ValType::Object) {}


JsonValue::JsonValue(const ::JsonArray& val) : _jArray(val), _type(ValType::Array) {}


JsonValue::JsonValue(std::shared_ptr<ObjectPtr> obj): _object(obj), _type(ValType::Empty)
{
    if (_object == nullptr || _object->valPtr.isEmpty()) {
        return;
    }
    
    if (_object->valPtr.isBoolean()) {
        _type = ValType::Bool;
        _boolVal = _object->valPtr.convert<bool>();
    }
    else if (_object->valPtr.isInteger()) {
        _type = ValType::Int;
        _intVal = _object->valPtr.convert<int>();
    }
    else if (_object->valPtr.isString()) {
        _type = ValType::String;
        _strVal = _object->valPtr.convert<std::string>();
    }
    else if (_object->valPtr.isVector() ||  _object->valPtr.isArray()) {
        _type = ValType::Array;
        _object->toJsonArray(_jArray);
    }
    else /* treat as object */ {
        _type = ValType::Object;
        _object->toJsonObject(_jObject);
    }
}

//JsonValue::JsonValue(const JsonValue& other) : _type(other._type), _jArray(other._jArray),
//                                                _jObject(other._jObject), _boolVal(other._boolVal),
//                                                _strVal(other._strVal), _intVal(other._intVal),
//                                                _object(other._object)
//{
//        std::cout << "copied";
//    
//    if (_object == nullptr || _object->valPtr.isEmpty()) {
//        return;
//    }
//    
//    if (_object->valPtr.isBoolean()) {
//        _type = ValType::Bool;
//        _boolVal = _object->valPtr.convert<bool>();
//    }
//    else if (_object->valPtr.isInteger()) {
//        _type = ValType::Int;
//        _intVal = _object->valPtr.convert<int>();
//    }
//    else if (_object->valPtr.isString()) {
//        _type = ValType::String;
//        _strVal = _object->valPtr.convert<std::string>();
//    }
//    else if (_object->valPtr.isVector()) {
//        _type = ValType::Array;
//        _object->toJsonArray(_jArray);
//    }
//    else /* treat as object */ {
//        _type = ValType::Object;
//        _object->toJsonObject(_jObject);
//    }
//    
//}


//JsonValue::JsonValue(JsonValue&& other) : _type(other._type), _jArray(other._jArray),
//_jObject(other._jObject), _boolVal(other._boolVal),
//_strVal(other._strVal), _intVal(other._intVal),
//_object(std::move(other._object))
//{
//    std::cout << "moved";
//}


std::unique_ptr<JsonValue> JsonValue::create(const std::string &json)
{
    auto o = std::make_shared<ObjectPtr>(json);
    return std::make_unique<JsonValue>(o);
}


bool JsonValue::isEmptyOrNull() const
{
    return _object == nullptr || _object->valPtr.isEmpty() || _type == ValType::Empty;
}


::JsonObject& JsonValue::asObject()
{
    return _jObject;
}


::JsonArray& JsonValue::asArray()
{
    return _jArray;
}


int JsonValue::asInt() const
{
    return _intVal;
}


bool JsonValue::asBool() const
{
    return _boolVal;
}


std::string JsonValue::asStr() const
{
    return _strVal;
}


std::string JsonValue::stringify(const JsonObject& obj)
{
    std::ostringstream objString;
    objString << "{";
    
    for (auto kvp = obj.begin(); kvp != obj.end(); kvp++) {
        objString << "\"" << kvp->first << "\":" << kvp->second.stringify();
        
        if (std::next(kvp) != obj.end()) {
            objString << ",";
        }
    }
    
    objString << "}";
    return objString.str();
}


std::string JsonValue::stringify(const JsonArray& jArray)
{
    std::ostringstream jsonString;
    jsonString << "[";

    for (auto val = jArray.begin(); val != jArray.end(); val++) {
        jsonString << val->stringify();
        
        if (std::next(val) != jArray.end()) {
            jsonString << ",";
        }
    }
    
    jsonString << "]";
    return jsonString.str();
}


std::string JsonValue::stringify() const
{
    if (isEmptyOrNull()) {
        return "null";
    }
    
    switch(_type) {
        case ValType::Bool:
            return _boolVal ? "true" : "false";
            
        case ValType::Int:
            return std::to_string(_intVal);
            
        case ValType::String:
            return "\"" + _strVal + "\"";
            
        case ValType::Object:
            return stringify(_jObject);

        case ValType::Array:
            return stringify(_jArray);
            
        default:
            throw "Unknown ValType";
    }
    
    return "";
}


JsonValue& JsonValue::operator[](const std::string& key)
{
    if (type() != ValType::Object) {
        throw "Invalid attempt to access non-object by key.";
    }
    
    return _jObject[key];
}


const JsonValue& JsonValue::operator[](const std::string& key) const
{
    return const_cast<JsonValue&>(*this)[key];
}