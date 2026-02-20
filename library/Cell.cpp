#include "Cell.h"

Cell::Cell(double currentEnergy) : currentEnergy(currentEnergy)
{
}

Cell::~Cell()
{

}

double Cell::chargeCell(double energy)
{
    int need = this->maxCapacity - this->currentEnergy;
    if (need < energy) {
        int remaning = energy - need;
        this->currentEnergy += need;
        return remaning;
    } else {
        this->currentEnergy += energy;
    }
    return 0;
}

double Cell::dischargeCell(double energy)
{
    double remaining;
    if(energy > this->currentEnergy) {
        remaining = energy - this->currentEnergy;
        this->currentEnergy = 0;
        return remaining;
    } else {
        this->currentEnergy -= energy;
    }
    return 0;
}

double Cell::getMaxCapacity() const
{
    return this->maxCapacity;
}

double Cell::getCurrentEnergy() const
{
    return this->currentEnergy;
}
