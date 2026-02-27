#pragma once

#include <SFML/Graphics.hpp>

class Component
{
    protected:
    //sf::RectangleShape shape;
        sf::Color color;
        sf::Vector2f position;
        sf::Clock clock;
        sf::Vector2f size;

        std::string type;
        bool isGrabbed;
        int coreValue;

        std::string name;
        sf::Font sharedFont; 
        bool fontLoaded;
        //sf::Text label;

        bool isTurnedOn = true;

    public:
        Component(sf::Vector2f pos, sf::Color color, std::string type, std::string name, int coreValue);
        virtual ~Component();
        
        virtual void draw(sf::RenderWindow& window);
        virtual void setDesign();
        
        void move(sf::RenderWindow& window);
        bool isRightClicked(sf::Vector2f mousePosition);
        Component* isLeftClicked(sf::Vector2f mousePosition);
        bool isClicked(sf::Vector2f mousePosition);
        void setPosition(sf::Vector2f pos);
        void setIsGrabbed(bool b);
        bool getIsGrapped() const;
        sf::RectangleShape getShape();
        void setName(std::string n);
        std::string getName() const;

        bool getIsTurnedOn() const;
        void setIsTurnedOn(bool b);
};

