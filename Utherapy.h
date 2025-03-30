#pragma once
#include "Treatment.h"
#include "UltrasoundDevice.h"
class Utherapy : public Treatment 
{
    UltrasoundDevice* assignedResource;
public:

    Utherapy(int d);

    bool canAssign(LinkedQueue<UltrasoundDevice>& resources, int currentTimestep, int& deviceID);

    void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList);

};

