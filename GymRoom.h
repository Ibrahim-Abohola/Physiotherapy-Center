#pragma once
#include "Resource.h"
#include "LinkedQueue.h"
using namespace std;

struct GymDevice 
{
    int id;
    bool isFree;
};

class GymRoom : public Resource 
{
    int capacity;
    LinkedQueue<GymDevice> devices;

public:
    GymRoom();
    GymRoom(int id, int cap, LinkedQueue<GymDevice> devs = {});

    bool allocate(int& room, int& device);

    void release(int deviceID);

    bool checkDeviceAvailability(int device);

    bool checkAvailability();

    bool isRoomFree();

    void setDeviceAvailability(int device, bool isFree);

};