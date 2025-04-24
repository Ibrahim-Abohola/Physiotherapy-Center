#pragma once
#include "Treatment.h"
#include "GymRoom.h"


class Scheduler;
class Patient;


class Xtherapy : public Treatment
{
   
public:

    Xtherapy(int d);

    virtual bool canAssign(Resource* r, int currentTime);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

	virtual char GetType();

};

