#include "UltrasoundDevice.h"

int U_Device::UID = 0;

U_Device::U_Device() : Resource("U_Device") {

    UID++;
    ID = UID;
}

int U_Device::getUID() const
{
    return ID;
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
    os << ID << " ";

}
