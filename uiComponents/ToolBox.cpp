#include "ToolBox.h"


ToolBox::ToolBox(tgui::BackendGuiSFML &gui)
{
    this->toolboxPanel = tgui::Panel::create();
    this->titleLabel = tgui::Label::create();
    this->setToolBox(gui);
}

void ToolBox::setToolBox(tgui::BackendGuiSFML &gui)
{
    this->toolboxPanel->setSize("20%", "100%");
    this->toolboxPanel->setPosition("0%", "0%");
    this->toolboxPanel->getRenderer()->setBackgroundColor(tgui::Color(33, 37, 43));

    this->titleLabel->setText("Toolbox");
    this->titleLabel->setTextSize(20);
    this->toolboxPanel->add(this->titleLabel);
    gui.add(this->toolboxPanel);
}

ToolBox::~ToolBox()
{

}
