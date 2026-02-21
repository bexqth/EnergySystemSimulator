#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "Workspace.h"

class ToolBox
{
    private:
        tgui::Panel::Ptr toolboxPanel;
        tgui::Label::Ptr titleLabel;
        std::vector<tgui::Button::Ptr> buttons;
        tgui::Button::Ptr generatorButton;
        tgui::Button::Ptr loadButton;
        tgui::Button::Ptr batteryButton;

        Workspace* workspace;
        
    public:
        ToolBox(tgui::BackendGuiSFML& gui, Workspace* workspace);
        void setToolBox(tgui::BackendGuiSFML &gui);
        void setButtons();
        void handleMouseClick(tgui::String buttonType);
        ~ToolBox();
};