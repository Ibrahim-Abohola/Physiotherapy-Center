#include "ETheraby.h"

ETherapy::ETherapy(int d) : Treatment(d) {}

bool ETherapy::canAssign(LinkedQueue<ElectrotherapyDevice>& resources, int currentTime, int& ID)
{
    ElectrotherapyDevice tempResource;

    LinkedQueue<ElectrotherapyDevice> tempQueue;

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
        ElectrotherapyDevice temp;

        tempQueue.dequeue(temp);

        resources.enqueue(temp);
    }

    return assigned;
}