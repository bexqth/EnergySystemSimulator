#include "ToolBox.h"
#include "Workspace.h"

ToolBox::ToolBox(tgui::BackendGuiSFML &gui, Workspace* workspace) : workspace(workspace)
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
    int startY = 40;
    int width = 180;
    int height = 40;
    int space = 15;

    for (size_t i = 0; i < buttons.size(); ++i)
    {
        buttons[i]->setText(labels[i]);
        buttons[i]->getRenderer()->setBackgroundColor(tgui::Color(58, 63, 69));
        buttons[i]->getRenderer()->setTextColor(tgui::Color(228, 229, 234));
        buttons[i]->getRenderer()->setTextSize(13);
        buttons[i]->getRenderer()->setBackgroundColorHover(tgui::Color(60, 60, 65));
        buttons[i]->setSize(width, height);
        float posY = startY + (i * (height + space));
        buttons[i]->setPosition(startX, posY);
        buttons[i]->onRightMousePress(&ToolBox::handleMouseClick, this, buttons[i]->getText());
        toolboxPanel->add(buttons[i]);
    }
}

void ToolBox::handleMouseClick(tgui::String buttonType)
{
    if (buttonType == "Gen") {
        this->workspace->addComponent("Gen");
    }
    std::cout << "button clicked " << buttonType << std::endl;
}

ToolBox::~ToolBox()
{

}
