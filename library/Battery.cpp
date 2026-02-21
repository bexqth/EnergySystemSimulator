#include "Battery.h"

Battery::Battery(sf::Vector2f pos) : Component(pos, sf::Color::Green, "Battery", "Battery")
{
}

Battery::~Battery()
{
    for (int i = 0; i < this->cells.size(); i++)
    {
        delete this->cells[i];
    }
}

void Battery::addCell(Cell* cell)
{
    this->cells.push_back(cell);
}

double Battery::chargeBattery(double amount)
{
    double remaining = amount;
    for (int i = 0; i < this->cells.size(); i++)
    {
        remaining = this->cells[i]->chargeCell(remaining);  
    }
    return remaining;
    
}

void Battery::dischargeBattery(double amount)
{
    double remaining = amount;
    for (int i = 0; i < this->cells.size(); i++)
    {
        remaining = this->cells[i]->dischargeCell(remaining);
    }
}

double Battery::getCapacity()
{
    double cap = 0;
    for (int i = 0; i < this->cells.size(); i++)
    {
        cap += this->cells[i]->getMaxCapacity();
    }
    return cap;
    
}

double Battery::getEnergy()
{
    double en = 0;
    for (int i = 0; i < this->cells.size(); i++)
    {
        en += this->cells[i]->getCurrentEnergy();
    }
    return en;
}
