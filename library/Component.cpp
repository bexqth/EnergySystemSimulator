#include "Component.h"
#include <iostream>

using namespace std;

Component::Component(sf::Vector2f position, sf::Color color, std::string type, std::string name, int coreValue) : position(position), color(color), type(type), name(name), coreValue(coreValue)
{   
    if (!fontLoaded) {
        if (sharedFont.openFromFile("assets/Roboto-Regular.ttf")) {
            fontLoaded = true;
        }
    }
    
    //this->shape.setSize({50.f, 50.f});
    //this->shape.setFillColor(color);
    //this->shape.setPosition(position);
}

Component::~Component()
{

}

void Component::draw(sf::RenderWindow &window)
{
}

void Component::setDesign()
{
}

/*void Component::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    sf::Text nameText(sharedFont, this->name, 12);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition({this->shape.getPosition().x, this->shape.getPosition().y - 20.f});
    window.draw(nameText);

    string textString;
    if(this->type == "Generator" || this->type == "Load") {
        textString = to_string(this->coreValue) + " kW";
    } else if(this->type == "Battery") {
        textString = to_string(this->coreValue) + " %";
    }

    sf::Text coreValueText(sharedFont, textString, 12);
    coreValueText.setFillColor(sf::Color::White);
    coreValueText.setPosition({this->shape.getPosition().x, this->shape.getPosition().y + 55.f});
    window.draw(coreValueText);
}*/



void Component::move(sf::RenderWindow& window)
{
    
}

bool Component::isRightClicked(sf::Vector2f mousePosition)
{
    //if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->shape.getSize().x && mousePosition.y < this->position.y + this->shape.getSize().y) {
    if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->size.x && mousePosition.y < this->position.y + this->size.y) {
        this->isGrabbed = (!this->isGrabbed);
        cout << "is grabbed: " << this->isGrabbed << endl;
        return true;
    }
    return false;
}

Component *Component::isLeftClicked(sf::Vector2f mousePosition)
{
    //if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->shape.getSize().x && mousePosition.y < this->position.y + this->shape.getSize().y) {
    if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->size.x && mousePosition.y < this->position.y + this->size.y) {
        return this;
    }
    return nullptr;
}

bool Component::isClicked(sf::Vector2f mousePosition)
{
    //if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->shape.getSize().x && mousePosition.y < this->position.y + this->shape.getSize().y) {
    if(mousePosition.x > this->position.x && mousePosition.y > this->position.y && mousePosition.x < this->position.x + this->size.x && mousePosition.y < this->position.y + this->size.y) {
        return true;
    }
    return false;
}

void Component::setPosition(sf::Vector2f pos) {
    this->position = pos;
    //this->shape.setPosition(pos);
}

void Component::setIsGrabbed(bool b)
{
    this->isGrabbed = b;
}

bool Component::getIsGrapped() const
{
    return this->isGrabbed;
}

sf::RectangleShape Component::getShape()
{
    //return this->shape;
}

void Component::setName(std::string n)
{
    this->name = n;
}

std::string Component::getName() const
{
    return this->name;
}

bool Component::getIsTurnedOn() const
{
    return this->isTurnedOn;
}

void Component::setIsTurnedOn(bool b)
{
    this->isTurnedOn = b;
}
