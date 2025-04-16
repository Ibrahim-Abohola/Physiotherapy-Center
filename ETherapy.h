#pragma once
#include "Treatment.h"
#include"ElectrotherapyDevice.h"

class Scheduler;
class Patient;



class ETherapy : public Treatment
{
public:
    ETherapy(int d);

    virtual bool canAssign(Resource* r, int currentTime);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

};

