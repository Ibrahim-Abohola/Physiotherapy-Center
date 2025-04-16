#include "ElectrotherapyDevice.h"
#include<iostream>

int E_Device::EID = 0;


E_Device::E_Device() : Resource("Electrotherapy") {
    
        EID++;
        ID = EID;
}


int E_Device::getEID() const
{
    return ID;
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

ostream& operator<<(ostream& os, const E_Device& p) {
    return os;
}

void E_Device::print(ostream& os) const
{
    os << ID << " ";

}