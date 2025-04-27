#include "UltrasoundDevice.h"

int U_Device::UID = 0;

U_Device::U_Device() : Resource("U") {

    UID++;
    ID = UID;
}

void U_Device::print(ostream& os) const
{
    os << ID << " ";

}
