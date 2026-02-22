#include "Workspace.h"
#include <iostream>
#include "../library/Component.h"
#include "../library/Generator.h"
#include "../library/Battery.h"
#include "../library/Load.h"

using namespace std;

Workspace::Workspace(tgui::BackendGuiSFML &gui, unsigned int winWidth, unsigned int winHeight, InfoBox infoBox) : winWidth(winWidth), winHeight(winHeight), infoBox(infoBox)
{
    this->workspacePanel = tgui::Panel::create();
    this->setWorkspace(gui);
    this->workspacePanel->onRightMousePress(&Workspace::handleRightMouseClick, this);
    this->workspacePanel->onMousePress(&Workspace::handleLeftMouseClick, this);
    this->grabbedComponent = nullptr;

    this->infoBox.getDeleteButton()->onClick(&Workspace::deleteComponent, this);
}

void Workspace::setWorkspace(tgui::BackendGuiSFML &gui)
{
    this->workspacePanel->setSize("60%", "100%");
    this->workspacePanel->setPosition("20%", "0%");
    this->workspacePanel->getRenderer()->setOpacity(0.f);

    gui.add(this->workspacePanel);
}

void Workspace::handleRightMouseClick(tgui::Vector2f pos)
{
    if(this->grabbedComponent != nullptr) {
        this->grabbedComponent->setIsGrabbed(false);
        this->grabbedComponent = nullptr;
        cout << "Component put down" << endl;
        return;

    } else {
        for (auto& com : this->components)
        {
            /*if(com->isRightClicked({pos.x + this->winWidth * 0.2f, pos.y})) {
                this->grabbedComponent = com.get();
                cout << "Component grabbed" << endl;
                return;
            }*/
           if(com->isClicked({pos.x + this->winWidth * 0.2f, pos.y})) {
                this->grabbedComponent = com.get();
                this->grabbedComponent->setIsGrabbed(!this->grabbedComponent->getIsGrapped());
                cout << "Component grabbed" << endl;
                return;
           }
        }
    }
}

void Workspace::handleLeftMouseClick(tgui::Vector2f pos)
{
    for (auto& com : this->components)
        {
            if(com->isClicked({pos.x + this->winWidth * 0.2f, pos.y})) {
                this->infoBox.setSelectedComponent(com.get());
                this->infoBox.displayInfo();
           }
        }
}

void Workspace::handleMouseMove(sf::Vector2f mousePos)
{
    if(this->grabbedComponent != nullptr) {
        float halfWidth = this->grabbedComponent->getShape().getSize().x / 2.0f;
        float halfHeight = this->grabbedComponent->getShape().getSize().y / 2.0f;
        this->grabbedComponent->setPosition({mousePos.x - halfWidth, mousePos.y - halfHeight});
    }
}

void Workspace::addComponent(std::string type)
{
    float posX = this->winWidth / 2;
    float posY = this->winHeight / 2;
    if(type == "Gen") {
        this->components.push_back(std::make_unique<Generator>(sf::Vector2f(posX, posY)));
    } else if(type == "Batt") {
        this->components.push_back(std::make_unique<Battery>(sf::Vector2f(posX, posY)));
    } else if(type == "Load") {
        this->components.push_back(std::make_unique<Load>(sf::Vector2f(posX, posY)));
    }
}

void Workspace::draw(sf::RenderWindow &window)
{
    for(auto& com : this->components) {
        com->draw(window);
    }
}

void Workspace::deleteComponent()
{
    Component* deletingComponent = infoBox.getSelectedComponent();
    if(deletingComponent != nullptr) {
        cout << "component " << deletingComponent->getName() << " deleted " << endl;
        for(int i = 0; i < this->components.size(); i++) {
            if(this->components[i].get() == deletingComponent) {
                this->components.erase(this->components.begin() + i);
                break;
            }
        }

        this->infoBox.setSelectedComponent(nullptr);
        this->infoBox.displayInfo();
    } else {
        cout << "NO COMPONENT SELECTED" << endl;
    }
}

Workspace::~Workspace()
{
}

