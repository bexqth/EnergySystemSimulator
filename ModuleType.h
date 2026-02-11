#pragma once

enum class ModuleType {
    ENGINE,
    TURBINE,
    CONTROL_UNIT,
    COOLING_SYSTEM
}

std::string getModuleTypeString(ModuleType type);