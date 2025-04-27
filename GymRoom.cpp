#include "GymRoom.h"
#include<iostream>
int GymRoom::RID = 0;


GymRoom::GymRoom(int roomSize) : Resource("R"), maxRoomSize(roomSize) {

    capacity =0;
    RID++;
    ID = RID;
}


bool GymRoom::allocate()
{
    if (!checkAvailability())
    {
        return false;
    }

    capacity++;

    return true;
}

void GymRoom::release()
{
    capacity--;
}

bool GymRoom::checkAvailability() const
{
    return capacity < maxRoomSize;
}

bool GymRoom::IsFull() {
	return capacity == maxRoomSize;
}

int GymRoom::getMaxRoomSize() const
{
    return maxRoomSize;
}

void GymRoom::print(ostream& os) const {
    os << "R" << ID << "[" << capacity << "," << maxRoomSize << "] ";
}
int GymRoom::getCurrentCapacity() const
{
    return capacity;
}