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

