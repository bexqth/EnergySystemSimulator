#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class ToolBox
{
    private:
        tgui::Panel::Ptr toolboxPanel;
        tgui::Label::Ptr titleLabel;

    public:
        ToolBox(tgui::BackendGuiSFML& gui);
        void setToolBox(tgui::BackendGuiSFML &gui);
        ~ToolBox();
};