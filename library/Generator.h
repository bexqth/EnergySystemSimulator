#pragma once
#include <vector>
#include "Module.h"
#include "Component.h"

class Generator : public Component
{
    private:
        bool isTurnedOn = true;
        std::vector<Module*> modules;

        sf::CircleShape glowCircle;
        sf::CircleShape mainCircle;
        sf::RectangleShape turbineRec;

    public:
        Generator(sf::Vector2f pos);
        ~Generator();
        void addModule(Module* module);
        void printInfo();
        void setIsTurnedOn(bool b);
        bool getIsTurnedOn();
        double getTotalProduction();

        void draw(sf::RenderWindow &window) override; 
        void setDesign() override;
};
