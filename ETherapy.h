#pragma once
#include "Treatment.h"
#include"ElectrotherapyDevice.h"
class ETherapy : public Treatment 
{
    ElectrotherapyDevice* assignedResource;
public:
    ETherapy(int d);

    bool canAssign(LinkedQueue<ElectrotherapyDevice>& resources, int currentTime, int& deviceID);

    void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList);

};

