#ifndef UTILS_H
#define UTILS_H


#include <map>

std::string sreplace(std::string haystack,
                      const std::string&  oldNeedle,
                      const std::string&  newNeedle);

std::string map_to_json(const std::map<std::string, std::string>*);

std::string jsonify(const std::string&);


#endif
