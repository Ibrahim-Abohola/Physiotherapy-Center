#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    electrotherapyDevices.enqueue(ElectrotherapyDevice(1));
    ultrasoundDevices.enqueue(UltrasoundDevice(2));
    gymRooms.enqueue(GymRoom(3, 5, LinkedQueue<string>()));
}

bool ResourceManager::allocateElectrotherapyDevice(ElectrotherapyDevice& device)
{
    return electrotherapyDevices.dequeue(device);
}
