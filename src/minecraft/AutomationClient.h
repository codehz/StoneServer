#pragma once

class IMinecraftApp;

namespace Automation {

class AutomationClient {

public:

    char filler[0x400];

    AutomationClient(IMinecraftApp& a);


};

}