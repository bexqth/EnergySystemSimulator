#pragma once
#include <vector>
#include "Cell.h"

class Battery
{
    private:
        std::vector<Cell*> cells;

    public:
        Battery();
        ~Battery();
        void addCell(Cell* cell);
        double chargeBattery(double amount);
        void dischargeBattery(double amount);
        double getCapacity();
        double getEnergy();
};
