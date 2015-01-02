#include  <vector>
#include <string>
#include <iostream>
#include <sstream>

#include <algorithm> 
#include <functional> 
#include <locale>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <iterator>
#include <map>

#include "Utils.h"



using namespace std;

#include <iomanip>
std::string jsonify(const std::string& s) {
    std::stringstream ss;
    for (size_t i = 0; i < s.length(); ++i) {
        if (unsigned(s[i]) < '\x20' || s[i] == '\\' || s[i] == '"') {
            ss << "\\u" << std::setfill('0') << std::setw(4) << std::hex << unsigned(s[i]);
        } else {
            ss << s[i];
        }
    }
    return ss.str();
}

std::string map_to_json(const map<string, string> *kvPairs) {
    stringstream jsonString;

    for(map<string,string>::const_iterator iterator = kvPairs->begin(); iterator != kvPairs->end(); iterator++) {
        // invoker repsonsible for formatting value correctly; eg, escaping string quotations marks, etc
        jsonString << "\"" << iterator->first << "\":" << iterator->second << ",";
    }

    return jsonString.str().substr(0, jsonString.str().size() - 1);;
}


long getMsTimeStamp() {

    struct timeval t1;
    long mtime;    
    long seconds, useconds;    

    gettimeofday(&t1, NULL);

    seconds  = t1.tv_sec;
    useconds = t1.tv_usec;

    //mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    mtime = seconds;
    mtime *= 1000;
    mtime += (useconds/1000.0);

    return mtime;
}

std::string randstring(int len)
{
   std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int pos;
   while(str.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    str.erase (pos, 1);
   }
   return str;
}

std::string sreplace(std::string haystack,
                      const std::string&  oldNeedle,
                      const std::string&  newNeedle) {

    std::string::size_type pos = 0;
    while ((pos = haystack.find(oldNeedle, pos)) != std::string::npos) {
         haystack.replace(pos, oldNeedle.length(), newNeedle);
         pos += newNeedle.length();
    }
    
    return haystack;

}


std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}
