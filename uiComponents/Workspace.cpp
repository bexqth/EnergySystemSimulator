#include "Workspace.h"
#include <iostream>

using namespace std;

Workspace::Workspace(tgui::BackendGuiSFML &gui)
{
    this->workspacePanel = tgui::Panel::create();
    this->setWorkspace(gui);
    this->workspacePanel->onRightMousePress(&Workspace::handleMouseClick, this);
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
    std::cout << pos.x << " " << pos.y << std::endl;
}

Workspace::~Workspace()
{
}

