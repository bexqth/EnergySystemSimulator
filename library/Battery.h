#pragma once
#include <vector>
#include "Cell.h"
#include "Component.h"

class Battery : public Component
{
    private:
        std::vector<Cell*> cells;

    public:
        Battery(sf::Vector2f pos);
        ~Battery();
        void addCell(Cell* cell);
        double chargeBattery(double amount);
        void dischargeBattery(double amount);
        double getCapacity();
        double getEnergy();

        void draw(sf::RenderWindow &window) override; 
        void setDesign() override;
};
