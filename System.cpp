#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::addGenerator(Generator *gen)
{
    this->generators.push_back(gen);
}

void System::addBattery(Battery *batt)
{
    this->bateries.push_back(batt);
}

void System::addLoad(Load *load)
{
    this->loads.push_back(load);
}

double System::getTotalConsumption() const
{
    return 0.0;
}

double System::getTotalProduction() const
{
    return 0.0;
}

void System::tick()
{
}
