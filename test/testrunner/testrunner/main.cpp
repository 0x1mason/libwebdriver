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
#include "Session.h"
#include <string>
#include <assert.h>

const char* e = "{\"status\":33,\"value\":{\"message\":\"A new session could not be created. (Original error: Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities)\",\"origValue\":\"Could not determine your device from Appium arguments or desired capabilities. Please make sure to specify the 'deviceName' and 'platformName' capabilities\"},\"sessionId\":\"null\"}"	;

//exports.iosTestApp = "http://appium.github.io/appium/assets/TestApp7.1.app.zip";
//exports.iosWebviewApp = "http://appium.github.io/appium/assets/WebViewApp7.1.app.zip";
//exports.iosUICatalogApp = "http://appium.github.io/appium/assets/UICatalog7.1.app.zip";
//exports.androidApiDemos = "http://appium.github.io/appium/assets/ApiDemos-debug.apk";
//exports.selendroidTestApp = "http://appium.github.io/appium/assets/selendroid-test-app-0.10.0.apk";
//exports.iosWebviewAppLocal = "http://localhost:3000/WebViewApp7.1.app.zip";
//exports.androidApiDemosLocal = "http://localhost:3000/ApiDemos-debug.apk";
// /Users/saucelabs/SauceLabs/appium/sample-code/apps/ApiDemos/bin/ApiDemos-debug.apk





void testSession()
{
    Capabilities caps = {{"browserName", ""},
        {"platformName", "Android"},
        {"platformVersion", "4.4.2"},
        {"deviceName", "android"},
      //  {"app", "http://appium.github.io/appium/assets/ApiDemos-debug.apk"}};
        {"app", "/Users/saucelabs/SauceLabs/appium/sample-code/apps/ApiDemos/bin/ApiDemos-debug.apk"}};
    
    auto session = Session::create("localhost:4723", caps);
    
    assert(session);
    assert(!session->id().empty());
}


int main(int argc, const char * argv[])
{
    testSession();
    
    return 0;
}
