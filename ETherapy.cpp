#include "ETherapy.h"

ETherapy::ETherapy(int d) : Treatment(d) {}

bool ETherapy::canAssign(LinkedQueue<ElectrotherapyDevice>& resources, int currentTime, int &deviceID)
{
    ElectrotherapyDevice tempResource(0);

    LinkedQueue<ElectrotherapyDevice> tempQueue;

    bool assigned = false;

    while (!resources.isEmpty()) 
    {
        resources.dequeue(tempResource);

        if (tempResource.checkAvailability()) 
        {
            assignedResource = &tempResource;

            assignmentTime = currentTime;

            tempResource.allocate(deviceID);

            assigned = true;
        }

        tempQueue.enqueue(tempResource);

        if (assigned) break;

    }
    while (!tempQueue.isEmpty()) 
    {

        ElectrotherapyDevice temp;

        tempQueue.dequeue(temp);

        resources.enqueue(temp);

    }

    return assigned;
}
