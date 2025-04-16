#pragma once
#include "Treatment.h"
#include "UltrasoundDevice.h"


class Scheduler;
class Patient;


class Utherapy : public Treatment
{
public:

    Utherapy(int d);

    virtual bool canAssign(Resource* r, int currentTime);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

};

