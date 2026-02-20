#pragma once
#include <SFML/Graphics.hpp>

class ToolBox : public sf::RectangleShape
{
    private:

    public:
        ToolBox(sf::Vector2f size, sf::Vector2f position);
        ~ToolBox();
};