#include "ModuleType.h"
#include <string>

using namespace std;

std::string getModuleTypeString(ModuleType type)
{
    switch (type)
    {
    case ModuleType::ENGINE:
        return "Engine";
    case ModuleType::TURBINE:
        return "Turbine";
    case ModuleType::CONTROL_UNIT:
        return "Control unit";
    case ModuleType::COOLING_SYSTEM:
        return "Cooling system";   
    default:
        return "Unknown";
    }
}