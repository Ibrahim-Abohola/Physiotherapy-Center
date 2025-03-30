#pragma once
#include "LinkedQueue.h"
#include "Resource.h"
#include "ElectrotherapyDevice.h"
#include "UltrasoundDevice.h"
#include "GymRoom.h"

class ResourceManager
{
    LinkedQueue<ElectrotherapyDevice> electrotherapyDevices;
    LinkedQueue<UltrasoundDevice> ultrasoundDevices;
    LinkedQueue<GymRoom> gymRooms;

public:
    ResourceManager();
    bool allocateElectrotherapyDevice(ElectrotherapyDevice& device);
};

