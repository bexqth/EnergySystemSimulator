#include "Module.h"
#include "ModuleType.h"
#include <iostream>

using namespace std;


Module::Module(ModuleType moduleType, double production) : moduleType(moduleType), production(production)
{
}

Module::~Module()
{
}

bool Module::getIsTurnedOn() const
{
    return this->isTurnedOn;
}

double Module::getProduction() const
{
    return this->production;
}

void Module::setIsTurnedOn(bool b)
{
    this->isTurnedOn = b;
}

void Module::printInfo()
{
    std::string state = this->isTurnedOn ? "ON" : "OFF";
    cout << getModuleTypeString(this->moduleType) << " " << state << ", production: " << this->production << endl;
}
