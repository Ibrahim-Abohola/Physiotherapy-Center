#pragma once
#include "Treatment.h"
#include "UltrasoundDevice.h"
class Utherapy : public Treatment
{
    UltrasoundDevice* assignedResource;
public:

    Utherapy(int d);

    bool canAssign(LinkedQueue<UltrasoundDevice>& resources, int currentTime, int& ID);

    void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList);

};

