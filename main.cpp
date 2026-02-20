#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "uiComponents/ToolBox.h"
#include "uiComponents/Workspace.h"

using namespace std;

int main() {
    /*System system;
    Generator* g1 = new Generator("G1");
    g1->addModule(new Module(ModuleType::ENGINE, 30.0));
    g1->addModule(new Module(ModuleType::TURBINE, 45.0));
    system.addGenerator(g1);

    Load* l1 = new Load(10.0);
    Load* l2 = new Load(15.0);
    system.addLoad(l1);
    system.addLoad(l2);

    system.tick();

    Battery battery;
    battery.addCell(new Cell(100.0));
    Load load(10.0);

    for (int i = 0; i < 4; i++)
    {
        battery.dischargeBattery(load.getConsumption());
        cout << "Batery current energy " << battery.getEnergy() << endl;
        cout << " " << endl;
    }*/
    
    unsigned int winWidth = 1000;
    unsigned int winHeight = 600;

    float sidebarWidth = winWidth * 0.2f;
    float workspaceWidth = winWidth * 0.8f;

    sf::RenderWindow window(sf::VideoMode({winWidth, winHeight}), "Energy System Simulation");
    window.setFramerateLimit(75);

    tgui::Gui gui{window};

    ToolBox toolBox(gui);
    Workspace workspace(gui);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            gui.handleEvent(*event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color(40, 44, 52));
        gui.draw();

        window.display();
    }

    return 0;
}
