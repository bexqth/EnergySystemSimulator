#include "Load.h"

Load::Load(double consumption, sf::Vector2f pos) : Component(pos, sf::Color::Blue, "Load", "Load"), consumption(consumption)
{

}

Load::~Load()
{
}

double Load::getConsumption() const
{
    return this->consumption;
}
