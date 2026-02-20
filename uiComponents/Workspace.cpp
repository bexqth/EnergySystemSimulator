#include "Workspace.h"

Workspace::Workspace(sf::Vector2f size, sf::Vector2f position)
{
    this->setSize(size);
    this->setPosition(position);
    this->setFillColor(sf::Color(40, 44, 52));
}

Workspace::~Workspace()
{
}

