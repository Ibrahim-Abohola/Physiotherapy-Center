#pragma once
#include "Treatment.h"
#include "GymRoom.h"
class Xtherapy : public Treatment
{
    GymRoom* assignedResource;
public:

    Xtherapy(int d);

    bool canAssign(LinkedQueue<GymRoom>& rooms, int currentTime, int& ID);

    void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList);

};

