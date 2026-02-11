#include "Generator.h"
#include <iostream>

using namespace std;

Generator::Generator(std::string name) : name(name)
{
}

Generator::~Generator()
{
}

void Generator::addModule(Module *module)
{
    this->modules.push_back(module);
}

double Generator::getWattage() const
{
    return this->wattage;
}

void Generator::printInfo()
{
    std::string state = this->isTurnedOn ? "ON" : "OFF";
    cout << this->name << " "<< this->getTotalProduction() << " " << state << endl;
    for (auto& module : this->modules)
    {
        module->printInfo();
    }
    
}

void Generator::setIsTurnedOn(bool b)
{
    this->isTurnedOn = b;
}

bool Generator::getIsTurnedOn()
{
    return this->isTurnedOn;
}

double Generator::getTotalProduction()
{
    double totalProd = 0.0;
    for(auto& module : this->modules) {
        if(module->getIsTurnedOn()) {
            totalProd += module->getProduction();
        }
    }
    return totalProd;
}
