#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class Workspace : public sf::RectangleShape
{
    private:
        tgui::Panel::Ptr workspacePanel;

    public:
        Workspace(tgui::BackendGuiSFML& gui);
        void setWorkspace(tgui::BackendGuiSFML& gui);
        void handleMouseClick(tgui::Vector2f pos);
        ~Workspace();
};
