#include "Generator.h"
#include <iostream>

using namespace std;

Generator::Generator(sf::Vector2f pos) : Component(pos, sf::Color::Yellow, "Generator", "Generator", 50)
{
    this->setDesign();
}

Generator::~Generator()
{
}

void Generator::addModule(Module *module)
{
    this->modules.push_back(module);
}

void Generator::draw(sf::RenderWindow &window) {

    window.draw(this->glowCircle);
    window.draw(this->mainCircle);
    window.draw(this->turbineRec);
    window.draw(this->turbineRecCol);

    sf::Text nameText(sharedFont, this->name, 12);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition({this->position.x - mainCircle.getRadius(), this->position.y - 25.f - mainCircle.getRadius()});
    window.draw(nameText);

    string textString = to_string(this->coreValue) + " kW";
    sf::Text coreValueText(sharedFont, textString, 12);
    coreValueText.setFillColor(sf::Color::White);
    coreValueText.setPosition({this->position.x - mainCircle.getRadius() + 10.f, this->position.y + 10.f + mainCircle.getRadius()});
    window.draw(coreValueText);

    //Component::draw(window);
}

void Generator::setDesign() {

    this->mainCircle.setRadius(25.f);
    this->mainCircle.setFillColor(sf::Color(40, 169, 215));
    this->mainCircle.setPosition(this->position);
    this->mainCircle.setOrigin({this->mainCircle.getRadius(), this->mainCircle.getRadius()});
    
    this->glowCircle.setRadius(32.f);
    this->glowCircle.setFillColor(sf::Color(this->mainCircle.getFillColor().r,this->mainCircle.getFillColor().g, this->mainCircle.getFillColor().b, 50));
    this->glowCircle.setOrigin({32.f, 32.f});
    this->glowCircle.setPosition({this->position.x, this->position.y});
    
    this->turbineRec.setSize({25.f, 5.f});
    this->turbineRec.setOrigin({12.5f, 2.5f});
    this->turbineRec.setPosition(this->position);
    this->turbineRec.setFillColor(sf::Color(243, 242, 241));

    this->turbineRecCol.setSize({25.f, 5.f});
    this->turbineRecCol.setOrigin({12.5f, 2.5f});
    this->turbineRecCol.setPosition(this->position);
    this->turbineRecCol.setFillColor(sf::Color(243, 242, 241));
    this->turbineRecCol.setRotation(sf::degrees(90.f));

    this->size = {64.f, 64.f};
}

void Generator::printInfo()
{
    std::string state = this->isTurnedOn ? "ON" : "OFF";
    cout << " " << std::round(this->getTotalProduction() * 100.0) / 100.0 << " " << state << endl;
    for (auto& module : this->modules)
    {
        cout << "  - ";
        module->printInfo();
    }
    
}

void Generator::setIsTurnedOn(bool b)
{
    this->isTurnedOn = b;
}

bool Generator::getIsTurnedOn()
{
    return this->isTurnedOn;
}

double Generator::getTotalProduction()
{
    double totalProd = 0.0;
    for(auto& module : this->modules) {
        if(module->getIsTurnedOn()) {
            totalProd += module->getProduction();
        }
    }
    return totalProd;
}
