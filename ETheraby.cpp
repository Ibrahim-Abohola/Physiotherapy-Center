#include "ETheraby.h"

ETherapy::ETherapy(int d) : Treatment(d) {}

bool ETherapy::canAssign(LinkedQueue<Resource * >& resources, int currentTime, int& ID)
{
    E_Device  * tempResource;

    LinkedQueue<E_Device * > tempQueue;

    bool assigned = false;

    while (!resources.isEmpty())
    {
        Resource* tempe;
        resources.dequeue(tempe);

        tempResource = dynamic_cast<E_Device*> (tempe);

        if (tempResource && tempResource->allocate())
        {
            AssignedResource = tempResource;

            setAssignmentTime(currentTime);

            tempResource->setAvailability(false);

            assigned = true;
        }

        tempQueue.enqueue(tempResource);

        if (assigned) break;
    }

    while (!tempQueue.isEmpty())
    {
        E_Device  * temp;

        tempQueue.dequeue(temp);

        resources.enqueue(temp);
    }

    return assigned;
}

void ETherapy::moveToWait()
{
    return;
}