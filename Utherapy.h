#pragma once
#include "Treatment.h"
#include "UltrasoundDevice.h"


class Scheduler;
class Patient;


class Utherapy : public Treatment
{
public:

    Utherapy(int d);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

	virtual char GetType();

};

