#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "../library/Component.h"


class Workspace : public sf::RectangleShape
{
    private:
        tgui::Panel::Ptr workspacePanel;
        std::vector<std::unique_ptr<Component>> components;
        unsigned int winWidth;
        unsigned int winHeight;
        Component* grabbedComponent;

    public:
        Workspace(tgui::BackendGuiSFML& gui, unsigned int winWidth, unsigned int winHeight);
        ~Workspace();
        void setWorkspace(tgui::BackendGuiSFML& gui);
        void handleMouseClick(tgui::Vector2f pos);
        void handleMouseMove(sf::Vector2f mousePos);
        void addComponent(std::string type);
        void draw(sf::RenderWindow& window);
};
