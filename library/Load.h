#pragma once
#include "Component.h"


class Load : public Component
{
    private:
        double consumption;
    public:
        Load(sf::Vector2f pos);
        ~Load();
        double getConsumption() const;
};

