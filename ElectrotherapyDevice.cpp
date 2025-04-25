#include "ElectrotherapyDevice.h"
#include<iostream>

int E_Device::EID = 0;


E_Device::E_Device() : Resource("E_Device") {
    
        EID++;
        ID = EID;
}


int E_Device::getEID() const
{
    return ID;
}

ostream& operator<<(ostream& os, const E_Device& p) {
    return os;
}

void E_Device::print(ostream& os) const
{
    os << ID << " ";

}