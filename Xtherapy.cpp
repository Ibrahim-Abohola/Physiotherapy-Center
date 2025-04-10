#include "Xtherapy.h"

Xtherapy::Xtherapy(int d) : Treatment(d) {}

bool Xtherapy::canAssign(LinkedQueue<Resource * >& rooms, int currentTime, int& ID)
{
    GymRoom * tempRoom;

    LinkedQueue<GymRoom *> tempQueue;

    bool assigned = false;

    while (!rooms.isEmpty())
    {
        Resource* tempr;
        rooms.dequeue(tempr);
        tempRoom = dynamic_cast<GymRoom*> (tempr);

        if (tempRoom && tempRoom->checkAvailability())
        {
            if (tempRoom->allocate())
            {
                AssignedResource = tempRoom;

                setAssignmentTime(currentTime);

                if (tempRoom->getCurrentCapacity() == 0)
                {
                    tempRoom->setAvailability(false);
                }

                assigned = true;
            }
        }

        tempQueue.enqueue(tempRoom);

        if (assigned) break;
    }

    while (!tempQueue.isEmpty())
    {
        GymRoom * temp;

        tempQueue.dequeue(temp);

        rooms.enqueue(temp);
    }

    return assigned;
}

void Xtherapy::moveToWait()
{
    return;
}
