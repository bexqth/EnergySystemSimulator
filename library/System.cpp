#include "System.h"
#include <iostream>

using namespace std;

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

double System::getTotalConsumption()
{
    double totalCon = 0.0;
    for(auto& load : this->loads) {
        totalCon += load->getConsumption();
    }
    this->totalConsumption = totalCon;
    return this->totalConsumption;
}

double System::getTotalProduction()
{
    double totalProd = 0.0;
    for(auto& gen : this->generators) {
        if(gen->getIsTurnedOn()) {
            totalProd += gen->getTotalProduction();
        }
    }
    this->totalProduction = totalProd;
    return this->totalProduction;
}

void System::tick()
{
    this->getTotalConsumption();
    this->getTotalProduction();

    cout << "Tick " << this->tickNumber << endl;
    cout << "Generators" << endl;
    for(auto& gen : this->generators) {
        gen->printInfo();
    }

    cout << "Total consumption: " << to_string(this->totalConsumption) << endl;
    cout << "Total production: " << to_string(this->totalProduction) << endl;
    this->printState();
    tickNumber++;
}

void System::printState()
{
    if(this->totalConsumption > this->totalProduction) {
        cout << "Alarm : consumption > production" << endl;
    } else {
        cout << "Alarm OK" << endl;
    }
}
