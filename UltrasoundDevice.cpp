#include "UltrasoundDevice.h"
#include <iostream>
int U_Device::UID = 0;

U_Device::U_Device() : Resource("Ultrasound", ++UID) {}

int U_Device::getUID() const
{
    return UID;
}

bool U_Device::allocate()
{
    if (checkAvailability())
    {
        setAvailability(false);
        return true;
    }
    return false;
}

void U_Device::release()
{
    setAvailability(true);
}

void U_Device::print(ostream& os) const
{
    os << UID;

}
