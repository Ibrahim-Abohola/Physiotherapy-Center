#include "UltrasoundDevice.h"

int UltrasoundDevice::UID = 0;

UltrasoundDevice::UltrasoundDevice() : Resource("Ultrasound", UID++) {}

int UltrasoundDevice::getUID() const
{
    return UID;
}

bool UltrasoundDevice::allocate(int& deviceID)
{
    if (checkAvailability())
    {
        setAvailability(false);
        deviceID = getUID();
        return true;
    }
    deviceID = -1;
    return false;
}

void UltrasoundDevice::release()
{
    setAvailability(true);
}
