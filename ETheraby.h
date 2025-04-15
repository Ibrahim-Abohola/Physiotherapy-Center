#pragma once
#include "Treatment.h"
#include"ElectrotherapyDevice.h"


class ETherapy : public Treatment
{
public:
    ETherapy(int d);

    virtual bool canAssign(LinkedQueue<Resource * >& resources, int currentTime, int& ID);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

};

