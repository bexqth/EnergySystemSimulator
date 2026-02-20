#include "Load.h"

Load::Load(double consumption) : consumption(consumption)
{

}

Load::~Load()
{
}

double Load::getConsumption() const
{
    return this->consumption;
}
