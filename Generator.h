#pragma once
#include <vector>
#include "Module.h"

class Generator
{
    private:
        std::string name;
        bool isTurnedOn;
        std::vector<Module*> modules;
    public:
        Generator(std::string name);
        ~Generator();
        void addModule(Module* module);
        void printInfo();
        void setIsTurnedOn(bool b);
        bool getIsTurnedOn();
        double getTotalProduction();
};
