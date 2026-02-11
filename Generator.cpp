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

void Generator::printInfo()
{
    std::string state = this->isTurnedOn ? "ON" : "OFF";
    cout << this->name << " " << std::round(this->getTotalProduction() * 100.0) / 100.0 << " " << state << endl;
    for (auto& module : this->modules)
    {
        cout << "  - ";
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
