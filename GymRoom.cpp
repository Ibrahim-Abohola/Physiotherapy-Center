#include "GymRoom.h"


GymRoom::GymRoom(): Resource("Gym", 0), capacity(0)
{
    LinkedQueue<GymDevice> emptyDevices;

    devices = emptyDevices;
}

GymRoom::GymRoom(int id, int cap, LinkedQueue<GymDevice> devs)

    : Resource("Gym", id), capacity(cap), devices(devs) {}


bool GymRoom::allocate(int& room, int& device) 
{
    if (!checkAvailability()) 
    {
        room = -1;
        device = -1;
        return false;
    }
    GymDevice currentDevice;

    LinkedQueue<GymDevice> tempQueue;

    bool allocated = false;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);

        if (currentDevice.isFree) 
        {
            currentDevice.isFree = false;

            room = getResourceID();

            device = currentDevice.id;

            allocated = true;
        }
        tempQueue.enqueue(currentDevice);

        if (allocated) break;
    }


    while (!tempQueue.isEmpty()) 
    {
        GymDevice tempDevice;

        tempQueue.dequeue(tempDevice);

        devices.enqueue(tempDevice);
    }

    if (!allocated) 
    {
        room = -1;
        device = -1;
    }

    return allocated;
}


void GymRoom::release(int deviceID) 
{
    GymDevice currentDevice;

    LinkedQueue<GymDevice> tempQueue;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);

        if (currentDevice.id == deviceID) 
        {
            currentDevice.isFree = true;
        }
        tempQueue.enqueue(currentDevice);
    }

    while (!tempQueue.isEmpty()) 
    {
        GymDevice tempDevice;

        tempQueue.dequeue(tempDevice);

        devices.enqueue(tempDevice);
    }

    capacity++;
    setAvailability(true);
}


bool GymRoom::checkDeviceAvailability(int device) 
{
    GymDevice currentDevice;

    LinkedQueue<GymDevice> tempQueue;

    bool found = false;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);

        if (currentDevice.id == device && currentDevice.isFree) 
        {
            found = true;
        }

        tempQueue.enqueue(currentDevice);
    }

    while (!tempQueue.isEmpty()) 
    {
        GymDevice tempDevice;

        tempQueue.dequeue(tempDevice);

        devices.enqueue(tempDevice);
    }

    return found;
}


bool GymRoom::checkAvailability() 
{
    return (isRoomFree() && capacity > 0);
}

bool GymRoom::isRoomFree() 
{
    GymDevice currentDevice;

    LinkedQueue<GymDevice> tempQueue;

    bool allBusy = true;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);

        if (currentDevice.isFree) 
        {
            allBusy = false;
        }

        tempQueue.enqueue(currentDevice);
    }

    while (!tempQueue.isEmpty()) 
    {
        GymDevice tempDevice;

        tempQueue.dequeue(tempDevice);

        devices.enqueue(tempDevice);
    }

    return !allBusy;
}

void GymRoom::setDeviceAvailability(int device, bool isFree) 
{
    GymDevice currentDevice;

    LinkedQueue<GymDevice> tempQueue;

    while (!devices.isEmpty()) 
    {
        devices.dequeue(currentDevice);

        if (currentDevice.id == device) 
        {
            currentDevice.isFree = isFree;
        }

        tempQueue.enqueue(currentDevice);
    }


    while (!tempQueue.isEmpty()) 
    {
        GymDevice tempDevice;

        tempQueue.dequeue(tempDevice);

        devices.enqueue(tempDevice);
    }
}