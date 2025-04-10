#pragma once
#include "Treatment.h"
#include "GymRoom.h"


class Xtherapy : public Treatment
{
   
public:

    Xtherapy(int d);

    virtual bool canAssign(LinkedQueue<Resource * >& rooms, int currentTime, int& ID);

    virtual void moveToWait();

};

