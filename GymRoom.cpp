#include "GymRoom.h"

int GymRoom::RID = 0;

GymRoom::GymRoom() : Resource("Gym", ++RID), maxRoomSize(0), capacity(0) {}

GymRoom::GymRoom(int roomSize) : Resource("Gym", RID++), maxRoomSize(roomSize), capacity(roomSize) {}

int GymRoom::getRID() const
{
    return RID;
}

bool GymRoom::allocate(int& RoomID)
{
    if (!checkAvailability())
    {
        return false;
    }

    RoomID = getRID();
    capacity--;

    return true;
}

void GymRoom::release()
{
    capacity++;
}

bool GymRoom::checkAvailability() const
{
    return capacity > 0;
}

int GymRoom::getMaxRoomSize() const
{
    return maxRoomSize;
}

int GymRoom::getCurrentCapacity() const
{
    return capacity;
}