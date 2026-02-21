#include "Component.h"
#include <iostream>

using namespace std;

Component::Component(sf::Vector2f position, sf::Color color, std::string type) : position(position), color(color), type(type)
{
    shape.setSize({50.f, 50.f});
    shape.setFillColor(this->color);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::White);
    shape.setPosition(this->position);
}

Component::~Component()
{

}

void Component::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

void Component::move(sf::RenderWindow& window)
{
    
}

bool Component::isClicked(sf::Vector2f mousePosition)
{
    if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->shape.getSize().x && mousePosition.y < this->position.y + this->shape.getSize().y) {
        this->isGrabbed = (!this->isGrabbed);
        cout << "is grabbed: " << this->isGrabbed << endl;
        return true;
    }
    return false;
}

void Component::setPosition(sf::Vector2f pos) {
    this->position = pos;
    this->shape.setPosition(pos);
}

void Component::setIsGrabbed(bool b)
{
    this->isGrabbed = b;
}

sf::RectangleShape Component::getShape()
{
    return this->shape;
}
