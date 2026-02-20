#include "ToolBox.h"

ToolBox::ToolBox(tgui::BackendGuiSFML &gui)
{
    this->toolboxPanel = tgui::Panel::create();
    this->titleLabel = tgui::Label::create();
    this->generatorButton = tgui::Button::create();
    this->loadButton = tgui::Button::create();
    this->batteryButton = tgui::Button::create();

    this->setToolBox(gui);
    this->setButtons();
}

void ToolBox::setToolBox(tgui::BackendGuiSFML &gui)
{
    this->toolboxPanel->setSize("20%", "100%");
    this->toolboxPanel->setPosition("0%", "0%");
    this->toolboxPanel->getRenderer()->setBackgroundColor(tgui::Color(33, 37, 43));

    this->titleLabel->setText("Toolbox");
    titleLabel->getRenderer()->setTextColor(tgui::Color::White);
    titleLabel->setOrigin(0.5f, 0.5f);
    titleLabel->setPosition("50%", 20);
    this->titleLabel->setTextSize(20);
    this->toolboxPanel->add(this->titleLabel);
    gui.add(this->toolboxPanel);
}

void ToolBox::setButtons()
{
    this->buttons.push_back(this->generatorButton);
    this->buttons.push_back(this->batteryButton);
    this->buttons.push_back(this->loadButton);

    std::vector<std::string> labels = {"Gen", "Batt", "Load"};
    int startX = 10;
    int startY = 60;
    int buttonSize = 50;
    int space = 10;

    for (size_t i = 0; i < buttons.size(); ++i)
    {
        buttons[i]->setText(labels[i]);
        buttons[i]->setSize(buttonSize, buttonSize);   
        float posX = startX + (i * (buttonSize + space));
        buttons[i]->setPosition(posX, startY);
        toolboxPanel->add(buttons[i]);
    }

}

ToolBox::~ToolBox()
{

}
