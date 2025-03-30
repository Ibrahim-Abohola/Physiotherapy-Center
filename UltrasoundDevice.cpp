#include "UltrasoundDevice.h"

UltrasoundDevice::UltrasoundDevice() : Resource("Ultrasound", 0) {}

UltrasoundDevice::UltrasoundDevice(int id): Resource("Ultrasound", id) {}

bool UltrasoundDevice::allocate(int& deviceID)
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

void UltrasoundDevice::release()
{
    setAvailability(true);
}
