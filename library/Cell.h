#pragma once

class Cell
{
    private:
        double maxCapacity = 100.0;
        double currentEnergy;
    public:
        Cell(double currentEnergy);
        ~Cell();
        double chargeCell(double energy);
        double dischargeCell(double energy);
        double getMaxCapacity() const;
        double getCurrentEnergy() const;
};

