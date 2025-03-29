#include "ElectrotherapyDevice.h"

ElectrotherapyDevice::ElectrotherapyDevice(int id) : Resource("Electro", id) {}

bool ElectrotherapyDevice::allocate()
{
    if (checkAvailability())
    {
        setAvailability(false);
        return true;
    }
    return false;
}

void ElectrotherapyDevice::release()
{
    setAvailability(true);
}
