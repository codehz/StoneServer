#pragma once

class IMinecraftApp;

namespace Automation {

class AutomationClient {

public:

    char filler[0x500];

    AutomationClient(IMinecraftApp& a);


};

}