#pragma once
#include <string>
#include "ModuleType.h"

class Module
{
    private:
        ModuleType moduleType;
        bool isTurnedOn;
        double production;
    public:
        Module(ModuleType moduleType, double production);
        ~Module();
        bool getIsTurnedOn() const;
        double getProduction() const;
        void setIsTurnedOn(bool b);
        void printInfo();
};