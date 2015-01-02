#ifndef COMMON_H
#define COMMON_H


#include <string>
//#include <memory>

#define QUICK_PROP_STR(name, setter) private: std::string _##name; public: std::string name () const { return _##name; } void setter (const std::string& v) { _##name = v; }


#endif