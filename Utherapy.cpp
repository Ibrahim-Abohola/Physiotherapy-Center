#include "Utherapy.h"

Utherapy::Utherapy(int d) : Treatment(d) {}

bool Utherapy::canAssign(LinkedQueue<Resource * >& resources, int currentTime, int& ID)
{
    U_Device * tempResource;

    LinkedQueue<U_Device * > tempQueue;

    bool assigned = false;

    while (!resources.isEmpty())
    {
        Resource * tempu;
        resources.dequeue(tempu);
        
        tempResource = dynamic_cast<U_Device*> (tempu);

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
        U_Device * temp;

        tempQueue.dequeue(temp);

        resources.enqueue(temp);
    }

    return assigned;
}

void Utherapy::moveToWait()
{
    return;
}