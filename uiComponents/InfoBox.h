#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <string>
#include "../library/Component.h"

class InfoBox
{
private:
    tgui::Panel::Ptr infoPanel;
    tgui::Label::Ptr titleLabel;
    tgui::Label::Ptr detailsTitle; 
    tgui::Label::Ptr logTitle;
    tgui::TextArea::Ptr logArea;

    tgui::Label::Ptr nameLabel;
    tgui::Label::Ptr statusLabel;
    tgui::Button::Ptr toggleButton;
    tgui::Slider::Ptr valueSlider;
    tgui::Label::Ptr valueLabel;

    tgui::EditBox::Ptr nameEdit;
    tgui::Button::Ptr saveButton;
    tgui::Button::Ptr deleteButton;

    Component* selectedComponent;

public:
    InfoBox(tgui::Gui& gui);
    ~InfoBox() = default;
    void setInfoBox(tgui::Gui& gui);
    void setSelectedComponent(Component* component);
    Component* getSelectedComponent();
    void displayInfo();
    void clearInfo();

    tgui::Button::Ptr getDeleteButton();

};
