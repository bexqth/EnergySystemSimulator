#include "Component.h"
#include <iostream>

using namespace std;

Component::Component(sf::Vector2f position, sf::Color color, std::string type, std::string name) : position(position), color(color), type(type), name(name)
{   
    if (!sharedFont.openFromFile("assets/Roboto-Regular.ttf")) {
        cout << "failed to load font " << endl;
    }

    this->shape.setSize({50.f, 50.f});
    this->shape.setFillColor(color);
    this->shape.setPosition(position);
}

Component::~Component()
{

}

void Component::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    sf::Text text(sharedFont, this->name, 12);
    text.setFillColor(sf::Color::White);
    text.setPosition({this->shape.getPosition().x, this->shape.getPosition().y - 20.f});
    window.draw(text);
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

void Component::setName(std::string n)
{
    this->name = n;
}

std::string Component::getName() const
{
    return this->name;
}
