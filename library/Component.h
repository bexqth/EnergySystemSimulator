#pragma once

#include <SFML/Graphics.hpp>

class Component
{
private:
    sf::RectangleShape shape;
    sf::Color color;
    sf::Vector2f position;
    std::string type;
    bool isGrabbed;

    std::string name;
    sf::Font sharedFont; 
    bool fontLoaded;
    //sf::Text label;

public:
    Component(sf::Vector2f pos, sf::Color color, std::string type, std::string name);
    virtual ~Component();
    void draw(sf::RenderWindow& window);
    void move(sf::RenderWindow& window);
    bool isClicked(sf::Vector2f mousePosition);
    void setPosition(sf::Vector2f pos);
    void setIsGrabbed(bool b);
    sf::RectangleShape getShape();
    void setName(std::string n);
    std::string getName() const;
};

