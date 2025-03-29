#include "UltrasoundDevice.h"

UltrasoundDevice::UltrasoundDevice(int id): Resource("Ultrasound", id) {}

bool UltrasoundDevice::allocate()
{
    if (checkAvailability())
    {
        setAvailability(false);
        return true;
    }
    return false;
}

void UltrasoundDevice::release()
{
    setAvailability(true);
}
