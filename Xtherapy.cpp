#include "Xtherapy.h"

Xtherapy::Xtherapy(int d) : Treatment(d) {}

bool Xtherapy::canAssign(LinkedQueue<GymRoom>& rooms, int currentTimestep, int& roomID, int& deviceID)
{
    GymRoom tempRoom;

    LinkedQueue<GymRoom> tempQueue;

    bool assigned = false;

    while (!rooms.isEmpty()) 
    {
        rooms.dequeue(tempRoom);

        if (tempRoom.checkAvailability()) 
        {
            if (tempRoom.allocate(roomID, deviceID)) 
            {
                assignedResource = &tempRoom;

                assignmentTime = currentTimestep;
                
                assigned = true;
            }
        }

        tempQueue.enqueue(tempRoom);

        if (assigned) break;
    }

    while (!tempQueue.isEmpty()) 
    {
        GymRoom temp;

        tempQueue.dequeue(temp);

        rooms.enqueue(temp);
    }

    return assigned;
}

 