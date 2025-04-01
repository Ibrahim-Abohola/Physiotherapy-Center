#include "Utherapy.h"

Utherapy::Utherapy(int d) : Treatment(d) {}

bool Utherapy::canAssign(LinkedQueue<UltrasoundDevice>& resources, int currentTime, int& ID)
{
    UltrasoundDevice tempResource;

    LinkedQueue<UltrasoundDevice> tempQueue;

    bool assigned = false;

    while (!resources.isEmpty())
    {
        resources.dequeue(tempResource);

        if (tempResource.allocate(ID))
        {
            assignedResource = &tempResource;

            setAssignmentTime(currentTime);

            tempResource.setAvailability(false);

            assigned = true;
        }
        tempQueue.enqueue(tempResource);

        if (assigned) break;
    }

    while (!tempQueue.isEmpty())
    {
        UltrasoundDevice temp;

        tempQueue.dequeue(temp);

        resources.enqueue(temp);
    }

    return assigned;
}