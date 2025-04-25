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

void U_Device::print(ostream& os) const
{
    os << ID << " ";

}
