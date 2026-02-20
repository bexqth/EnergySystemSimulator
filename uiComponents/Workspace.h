#pragma once
#include <SFML/Graphics.hpp>

class Workspace : public sf::RectangleShape
{
    private:
        sf::RectangleShape background;
    public:
        Workspace(sf::Vector2f size, sf::Vector2f position);
        ~Workspace();
};
