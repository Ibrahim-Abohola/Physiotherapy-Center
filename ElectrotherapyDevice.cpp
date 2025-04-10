#include "ElectrotherapyDevice.h"


int E_Device::EID = 0;


E_Device::E_Device() : Resource("Electrotherapy", ++EID) {}


int E_Device::getEID() const
{
    return EID;
}

bool E_Device::allocate()
{
    if (checkAvailability())
    {
        setAvailability(false);
        return true;
    }
    return false;
}

void E_Device::release()
{
    setAvailability(true);
}
