#pragma once
#include"Resource.h"
#include"LinkedQueue.h"
class Treatment
{

    int duration;
protected:
    int assignmentTime;

public:
    Treatment(int d);
    void setDuration(int du);
    int getDuration();
    void setAssignmentTime(int at);
    int getAssignmentTime();

    virtual bool canAssign(LinkedQueue<Resource>& resources, int currentTime, int& ID) = 0;

    virtual void moveToWait(Patient& patient, LinkedQueue<Patient>& waitingList) = 0;

    virtual ~Treatment() {}
};

