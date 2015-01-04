//
//  main.cpp
//  testrunner
//
//  Created by Sauce Labs on 1/2/15.
//  Copyright (c) 2015 Ox1mason. All rights reserved.
//

#include <sys/time.h>
#include <iostream>
#include <utility>
#include "JsonValue.h"
#include "Session.h"
#include <string>

const char* e = "{\"status\":33,\"value\":{\"message\":\"A new session could not be created. (Original error: Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities)\",\"origValue\":\"Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities\"},\"sessionId\":\"null\"}"	;

struct A {
    std::string s;
    A() : s("test") {}
    A(const A& o) : s(o.s) { std::cout << "move failed!\n";}
    A(A&& o) : s(std::move(o.s)) {}
    A& operator=(const A&) { std::cout << "copy assigned\n"; return *this; }
    A& operator=(A&& other) {
        s = std::move(other.s);
        std::cout << "move assigned\n";
        return *this;
    }
};

A f(A a) { return a; }

void moveTest()
{
    A a1, a2;
    std::cout << "Trying to move-assign A from rvalue temporary\n";
    a1 = f(A()); // move-assignment from rvalue temporary
    std::cout << "Trying to move-assign A from xvalue\n";
    a2 = std::move(a1); // move-assignment from xvalue
}


std::unique_ptr<JsonValue> x()
{
    //return JsonValue::create(e);
    return JsonValue::create2(e);
}

JsonValue y()
{
   // JsonValue j(e);
  //  return j;
    return JsonValue::create(e);
}


void moveNum()
{
    std::string s = std::move(e);
   // double start = 0;
   // double end = 5;
  //  start = std::move(end);
    //return JsonValue::create(e);
    //return std::make_unique<JsonValue>(e);
}

void copyNum()
{
        std::string s(e);
//    double start = 0;
//    double end = 5;
//    start = end;
    //    JsonValue j(e);
    //    return j;
    //return JsonValue::create2(e);
}

typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}


void benchmarkCopyVsMove()
{
    // Starting the time measurement
    double start = 0;
    double end = 0;
    
    start = get_timestamp ();
    // Computations to be measured
    for(int i = 0; i < 10000; i++) {
        moveNum();
    }
    // Measuring the elapsed time
    end = get_timestamp ();
    std::cout << "Move: " << (end - start) << "\n";
    // Time calculation (in seconds)
    start = 0;
    end = 0;
    
    // std::unique_ptr<JsonValue> w;
    start = get_timestamp ();
    // Computations to be measured
    
    for(int z = 0; z < 10000; z++) {
        copyNum();
        //y();
        //  std::unique_ptr<JsonValue> w();
    }
    // Measuring the elapsed time
    end = get_timestamp ();
    std::cout << "Copy: " << (end - start) << "\n";
}


void benchmarkCopyVsPtr()
{
    // Starting the time measurement
    double start = 0;
    double end = 0;
    
    start = get_timestamp ();
    // Computations to be measured
    for(int i = 0; i < 10000; i++) {
        auto g = x();
    }
    // Measuring the elapsed time
    end = get_timestamp ();
    std::cout << "Unique ptr: " << (end - start) << "\n";
    // Time calculation (in seconds)
    start = 0;
    end = 0;
    
   // std::unique_ptr<JsonValue> w;
    start = get_timestamp ();
    // Computations to be measured

    for(int z = 0; z < 10000; z++) {
        auto h = y();
      //  std::unique_ptr<JsonValue> w();
    }
    // Measuring the elapsed time
    end = get_timestamp ();
    std::cout << "Copy: " << (end - start) << "\n";
}

//exports.iosTestApp = "http://appium.github.io/appium/assets/TestApp7.1.app.zip";
//exports.iosWebviewApp = "http://appium.github.io/appium/assets/WebViewApp7.1.app.zip";
//exports.iosUICatalogApp = "http://appium.github.io/appium/assets/UICatalog7.1.app.zip";
//exports.androidApiDemos = "http://appium.github.io/appium/assets/ApiDemos-debug.apk";
//exports.selendroidTestApp = "http://appium.github.io/appium/assets/selendroid-test-app-0.10.0.apk";
//exports.iosWebviewAppLocal = "http://localhost:3000/WebViewApp7.1.app.zip";
//exports.androidApiDemosLocal = "http://localhost:3000/ApiDemos-debug.apk";

int main(int argc, const char * argv[]) {
   // moveTest();
   // benchmarkCopyVsMove();
//    int a = 0;
//    int b = 5;
//    a = std::move(b);
//    std::cout << "a: " << a << " b: " << b;
   //benchmarkCopyVsPtr();
    Capabilities caps = {{"browserName", ""}, {"platformName", "Android"}, {"platformVersion", "4.4.2"}, {"deviceName", "Android Emulator"}, {"app", "http://appium.github.io/appium/assets/ApiDemos-debug.apk"}};
    Session::create("localhost:4723", caps);
    return 0;
}
