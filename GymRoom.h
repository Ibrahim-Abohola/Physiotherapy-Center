#pragma once
#include "Resource.h"
#include "LinkedQueue.h"

class GymRoom : public Resource 
{
    int capacity;
    LinkedQueue<string> devices;

public:
    GymRoom(int id, int cap, LinkedQueue<string> devs = {});

    bool allocate();

    void release();

    bool checkDeviceAvailability(const string& device);
    bool checkAvailability() const;
};

