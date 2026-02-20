#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class ToolBox
{
    private:
        tgui::Panel::Ptr toolboxPanel;
        tgui::Label::Ptr titleLabel;
        std::vector<tgui::Button::Ptr> buttons;
        tgui::Button::Ptr generatorButton;
        tgui::Button::Ptr loadButton;
        tgui::Button::Ptr batteryButton;

    public:
        ToolBox(tgui::BackendGuiSFML& gui);
        void setToolBox(tgui::BackendGuiSFML &gui);
        void setButtons();
        ~ToolBox();
};