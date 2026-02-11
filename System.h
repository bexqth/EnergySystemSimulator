#pragma once
#include <vector>
#include "Battery.h"
#include "Load.h"
#include "Generator.h"

class System
{
    private:
        std::vector<Battery*> bateries;
        std::vector<Load*> loads;
        std::vector<Generator*> generators;
        int step;
        int totalConsumption;
        int totalProduction;
    public:
        System();
        ~System();
        void addGenerator(Generator* gen);
        void addBattery(Battery* batt);
        void addLoad(Load* load);
        double getTotalConsumption() const;
        double getTotalProduction() const;
        void tick();
};