#pragma once
#include "Resource.h"
#include "LinkedQueue.h"

class GymRoom : public Resource {
private:
    static int RID;
    int maxRoomSize;
    int capacity;

public:
    GymRoom();
    GymRoom(int roomSize);

    int getRID() const;

    bool allocate(int& RoomID);

    void release();

    bool checkAvailability() const;

    int getMaxRoomSize() const;

    int getCurrentCapacity() const;
};