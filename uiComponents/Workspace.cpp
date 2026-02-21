#include "Workspace.h"
#include <iostream>
#include "../library/Component.h"
#include "../library/Generator.h"
#include "../library/Battery.h"
#include "../library/Load.h"

using namespace std;

Workspace::Workspace(tgui::BackendGuiSFML &gui, unsigned int winWidth, unsigned int winHeight) : winWidth(winWidth), winHeight(winHeight)
{
    this->workspacePanel = tgui::Panel::create();
    this->setWorkspace(gui);
    this->workspacePanel->onRightMousePress(&Workspace::handleMouseClick, this);
    this->grabbedComponent = nullptr;
}

void Workspace::setWorkspace(tgui::BackendGuiSFML &gui)
{
    this->workspacePanel->setSize("60%", "100%");
    this->workspacePanel->setPosition("20%", "0%");
    this->workspacePanel->getRenderer()->setOpacity(0.f);

    gui.add(this->workspacePanel);
}

void Workspace::handleMouseClick(tgui::Vector2f pos)
{
    if(this->grabbedComponent != nullptr) {
        this->grabbedComponent->setIsGrabbed(false);
        this->grabbedComponent = nullptr;
        cout << "Component put down" << endl;
        return;

    } else {
        for (auto& com : this->components)
        {
            if(com->isClicked({pos.x + this->winWidth * 0.2f, pos.y})) {
                this->grabbedComponent = com.get();
                cout << "Component grabbed" << endl;
                return;
            }
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
        this->components.push_back(std::make_unique<Load>(15.5, sf::Vector2f(posX, posY)));
    }
}

void Workspace::draw(sf::RenderWindow &window)
{
    for(auto& com : this->components) {
        com->draw(window);
    }
}

Workspace::~Workspace()
{
}

