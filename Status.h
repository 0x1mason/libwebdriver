/* 
 * File:   Status.h
 * Author: saucelabs
 *
 * Created on December 22, 2014, 12:49 PM
 */

#ifndef STATUS_H
#define	STATUS_H


#include "Common.h"
#include "JsonValue.h"

struct Status
{
    
public:
    Status(JsonObject& build, JsonObject& os)
    {
        setBuildVersion(build["version"].asStr());
        setBuildRevision(build["revision"].asStr());
        setBuildTime(build["time"].asStr());
        
        setOsArch(os["arch"].asStr());
        setOsName(os["name"].asStr());
        setOsVersion(os["version"].asStr());
        
    }
    
	QUICK_PROP_STR(buildVersion, setBuildVersion);
	QUICK_PROP_STR(buildRevision, setBuildRevision);
	QUICK_PROP_STR(buildTime, setBuildTime);

	QUICK_PROP_STR(osArch, setOsArch);
	QUICK_PROP_STR(osName, setOsName);
	QUICK_PROP_STR(osVersion, setOsVersion);
};

#endif	/* STATUS_H */

