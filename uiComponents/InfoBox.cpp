#include "InfoBox.h"
#include "Workspace.h"

using namespace std;

InfoBox::InfoBox(tgui::Gui& gui)
{
    this->infoPanel = tgui::Panel::create();
    this->titleLabel = tgui::Label::create();
    this->detailsTitle = tgui::Label::create();
    this->logTitle = tgui::Label::create();
    this->logArea = tgui::TextArea::create();

    this->nameLabel = tgui::Label::create();
    this->statusLabel = tgui::Label::create();
    this->toggleButton = tgui::Button::create();
    this->valueSlider = tgui::Slider::create();
    this->valueLabel = tgui::Label::create();

    this->nameEdit = tgui::EditBox::create();
    this->saveButton = tgui::Button::create();
    this->deleteButton = tgui::Button::create();

    this->setInfoBox(gui);
}

void InfoBox::setInfoBox(tgui::Gui& gui)
{
    this->infoPanel->setSize("20%", "100%");
    this->infoPanel->setPosition("80%", "0%");
    this->infoPanel->getRenderer()->setBackgroundColor(tgui::Color(33, 37, 43));
    this->infoPanel->getRenderer()->setPadding({10, 10, 10, 10});

    this->titleLabel->setText("INFO PANEL");
    this->titleLabel->setTextSize(18);
    this->titleLabel->getRenderer()->setTextColor(tgui::Color::White);
    this->titleLabel->setPosition("(parent.width - width) / 2", 20);
    this->infoPanel->add(this->titleLabel);

    this->nameLabel->setText("Name:");
    this->nameLabel->setTextSize(11);
    this->nameLabel->setPosition(15, 70);
    this->nameLabel->getRenderer()->setTextColor(tgui::Color::White);
    this->infoPanel->add(this->nameLabel);

    this->nameEdit->setSize("100% - 30", 25);
    this->nameEdit->setPosition(15, 85);
    this->nameEdit->getRenderer()->setBackgroundColor(tgui::Color(45, 50, 58));
    this->nameEdit->getRenderer()->setTextColor(tgui::Color::White);
    this->infoPanel->add(this->nameEdit);

    this->statusLabel->setText("Status: Unknown");
    this->statusLabel->setPosition(15, 120);
    this->statusLabel->getRenderer()->setTextColor(tgui::Color::White);
    this->infoPanel->add(this->statusLabel);

    this->toggleButton->setText("ON / OFF");
    this->toggleButton->setSize("100% - 30", 30);
    this->toggleButton->setPosition(15, 140);
    this->infoPanel->add(this->toggleButton);

    this->valueLabel->setText("Adjust Value:");
    this->valueLabel->setPosition(15, 185);
    this->valueLabel->getRenderer()->setTextColor(tgui::Color::White);
    this->infoPanel->add(this->valueLabel);

    this->valueSlider->setSize("100% - 30", 12);
    this->valueSlider->setPosition(15, 205);
    this->infoPanel->add(this->valueSlider);

    this->saveButton->setText("APPLY");
    this->saveButton->setSize("100% - 30", 30);
    this->saveButton->setPosition(15, 235);
    this->saveButton->getRenderer()->setBackgroundColor(tgui::Color(46, 139, 87));
    this->saveButton->getRenderer()->setTextColor(tgui::Color::White);
    this->infoPanel->add(this->saveButton);

    this->deleteButton->setText("DELETE");
    this->deleteButton->setSize("100% - 30", 30);
    this->deleteButton->setPosition(15, 275);
    auto delRenderer = this->deleteButton->getRenderer();
    delRenderer->setBackgroundColor(tgui::Color(150, 50, 50));
    delRenderer->setTextColor(tgui::Color::White);
    delRenderer->setBackgroundColorHover(tgui::Color(200, 60, 60));
    this->infoPanel->add(this->deleteButton);

    this->logTitle->setText("SYSTEM LOGS");
    this->logTitle->getRenderer()->setTextColor(tgui::Color::White);
    this->logTitle->setPosition(15, 330);
    this->infoPanel->add(this->logTitle);

    this->logArea->setSize("100% - 30", "100% - 370");
    this->logArea->setPosition(15, 350);
    this->logArea->getRenderer()->setBackgroundColor(tgui::Color(25, 28, 33));
    this->logArea->getRenderer()->setTextColor(tgui::Color(0, 255, 0));
    this->infoPanel->add(this->logArea);

    gui.add(this->infoPanel);
}

void InfoBox::setSelectedComponent(Component* component)
{
    this->selectedComponent = component;
}

Component *InfoBox::getSelectedComponent()
{
    return this->selectedComponent;
}

void InfoBox::displayInfo()
{
    if(this->selectedComponent != nullptr) {
        this->nameEdit->setText(this->selectedComponent->getName());
        string status;
        if(this->selectedComponent->getIsTurnedOn()) {
            status = "ON";
        } else {
            status = "OFF";
        }
        this->statusLabel->setText("Status: " + status);
    } else {
        this->clearInfo();
    }
}

void InfoBox::clearInfo()
{
    this->nameEdit->setText("");
    this->statusLabel->setText("Status: Unknown");
}

tgui::Button::Ptr InfoBox::getDeleteButton()
{
    return this->deleteButton;
}
