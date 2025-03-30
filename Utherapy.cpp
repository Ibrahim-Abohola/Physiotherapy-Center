#include "Utherapy.h"

Utherapy::Utherapy(int d): Treatment(d) {}

bool Utherapy::canAssign(LinkedQueue<UltrasoundDevice>& resources, int currentTimestep, int& deviceID)
{
    UltrasoundDevice tempResource(0);

    LinkedQueue<UltrasoundDevice> tempQueue;

    bool assigned = false;

    while (!resources.isEmpty()) 
    {
        resources.dequeue(tempResource);

        if (tempResource.checkAvailability()) 
        {
            assignedResource = &tempResource;

            assignmentTime = currentTimestep;

            tempResource.allocate(deviceID);

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
