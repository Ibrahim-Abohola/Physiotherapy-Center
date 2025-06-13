#pragma once
#include "Treatment.h"
#include"ElectrotherapyDevice.h"

class Scheduler;
class Patient;



class ETherapy : public Treatment
{
public:
    ETherapy(int d);

    virtual void moveToWait(Patient* p, Scheduler* scheduler);

	virtual char GetType();

};

