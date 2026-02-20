#include "ToolBox.h"


ToolBox::ToolBox(sf::Vector2f size, sf::Vector2f position)
{
    this->setSize(size);
    this->setPosition(position);
    this->setFillColor(sf::Color(33, 37, 43));
}

ToolBox::~ToolBox()
{

}
