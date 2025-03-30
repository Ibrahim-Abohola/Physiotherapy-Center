#pragma once
#include "Treatment.h"
#include "GymRoom.h"
class Xtherapy: public Treatment 
{
    GymRoom* assignedResource;
public:

    Xtherapy(int d);

    bool canAssign(LinkedQueue<GymRoom>& rooms, int currentTimestep, int& roomID, int& deviceID);

    void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList);

};

