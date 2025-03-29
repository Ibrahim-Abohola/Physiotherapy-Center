#include "GymRoom.h"

GymRoom::GymRoom(int id, int cap, LinkedQueue<string> devs)
    : Resource("Gym", id), capacity(cap), devices(devs) {}

bool GymRoom::allocate()
{
    if (checkAvailability() && capacity > 0)
    {
        capacity--;
        if (capacity == 0) {
            setAvailability(false);
        }
        return true;
    }
    return false;
}

void GymRoom::release()
{
    capacity++;
    setAvailability(true);
}

bool GymRoom::checkDeviceAvailability(const string& device) 
{
    if (capacity == 0)
    {
        return false;
    }

    string currentDevice;
    LinkedQueue<string> tempQueue;
    bool found = false;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);
        if (currentDevice == device) {
            found = true;
        }
        tempQueue.enqueue(currentDevice);
    }
    while (!tempQueue.isEmpty()) 
    {
        string tempDevice;
        tempQueue.dequeue(tempDevice);
        devices.enqueue(tempDevice);
    }

    return found;
}

bool GymRoom::checkAvailability() const
{
    return (checkAvailability() && capacity > 0);
}
