#include "ElectrotherapyDevice.h"

ElectrotherapyDevice::ElectrotherapyDevice() : Resource("Electro", 0) {}

ElectrotherapyDevice::ElectrotherapyDevice(int id) : Resource("Electro", id) {}

bool ElectrotherapyDevice::allocate(int& deviceID)
{
    if (checkAvailability())
    {
        setAvailability(false);
        deviceID = getResourceID();
        return true;
    }
    deviceID = -1;
    return false;
}

void ElectrotherapyDevice::release()
{
    setAvailability(true);
}
