#include "Load.h"

Load::Load(sf::Vector2f pos) : Component(pos, sf::Color::Blue, "Load", "Load", 15)
{
    
}

Load::~Load()
{
}

double Load::getConsumption() const
{
    return this->consumption;
}
