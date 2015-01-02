//
//  main.cpp
//  testrunner
//
//  Created by Sauce Labs on 1/2/15.
//  Copyright (c) 2015 Ox1mason. All rights reserved.
//

#include <sys/time.h>
#include <iostream>
#include "JsonValue.h"
#include "make_unique.h"


const char* e = "{\"status\":33,\"value\":{\"message\":\"A new session could not be created. (Original error: Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities)\",\"origValue\":\"Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities\"},\"sessionId\":\"null\"}"	;

std::unique_ptr<JsonValue> x()
{
    return JsonValue::create(e);
    //return std::make_unique<JsonValue>(e);
}

JsonValue y()
{
//    JsonValue j(e);
//    return j;
    return JsonValue::create2(e);
}

typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}


void benchmarkCopyVsPtr()
{
    // Starting the time measurement
    double start = get_timestamp ();
    // Computations to be measured
    JsonValue j;
    for(int i = 0; i < 1000; i++) {
        x();
    }
    // Measuring the elapsed time
    double end = get_timestamp ();
    std::cout << "Unique ptr: " << (end - start) << "\n";
    // Time calculation (in seconds)
    start = 0;
    end = 0;
    
   // std::unique_ptr<JsonValue> w;
    start = get_timestamp ();
    // Computations to be measured

    for(int z = 0; z < 1000; z++) {
        y();
      //  std::unique_ptr<JsonValue> w();
    }
    // Measuring the elapsed time
    end = get_timestamp ();
    std::cout << "Copy: " << (end - start) << "\n";
}


int main(int argc, const char * argv[]) {
    benchmarkCopyVsPtr();
    return 0;
}
