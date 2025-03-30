#include "ElectrotherapyDevice.h"


int ElectrotherapyDevice::EID = 0;


ElectrotherapyDevice::ElectrotherapyDevice() : Resource("Electrotherapy", EID++) {}


int ElectrotherapyDevice::getEID() const
{
    return EID;
}

bool ElectrotherapyDevice::allocate(int& deviceID)
{
    if (checkAvailability())
    {
        setAvailability(false);
        deviceID = getEID();
        return true;
    }
    deviceID = -1;
    return false;
}

void ElectrotherapyDevice::release()
{
    setAvailability(true);
}
