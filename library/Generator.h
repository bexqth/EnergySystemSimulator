#pragma once
#include <vector>
#include "Module.h"
#include "Component.h"

class Generator : public Component
{
    private:
        bool isTurnedOn = true;
        std::vector<Module*> modules;
    public:
        Generator(sf::Vector2f pos);
        ~Generator();
        void addModule(Module* module);
        void printInfo();
        void setIsTurnedOn(bool b);
        bool getIsTurnedOn();
        double getTotalProduction();
};
