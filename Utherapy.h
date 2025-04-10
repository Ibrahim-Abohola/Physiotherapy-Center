#pragma once
#include "Treatment.h"
#include "UltrasoundDevice.h"


class Utherapy : public Treatment
{
public:

    Utherapy(int d);

    virtual bool canAssign(LinkedQueue<Resource * >& resources, int currentTime, int& ID);

    virtual void moveToWait();

};

