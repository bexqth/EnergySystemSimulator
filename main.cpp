#include <iostream>
#include "Cell.h"
#include "Battery.h"
#include "Load.h"
#include "Generator.h"

using namespace std;

int main() {
    Generator generator("G1");
    generator.addModule(new Module(ModuleType::ENGINE, 30.0));
    generator.addModule(new Module(ModuleType::TURBINE, 45.0));
    generator.printInfo();
    
    Battery battery;
    battery.addCell(new Cell(100.0));
    Load load(10.0);

    for (int i = 0; i < 4; i++)
    {
        battery.dischargeBattery(load.getConsumption());
        cout << "Batery current energy " << battery.getEnergy() << endl;
        cout << " " << endl;
    }
    
    return 0;
}
