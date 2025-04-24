#pragma once
#include"Resource.h"
#include"LinkedQueue.h"

class Scheduler;
class Patient;

class Treatment
{

    int duration;
protected:
    int AssignmentTime;
    Resource* AssignedResource;
    string type;
public:
    Treatment(int d);
    void setDuration(int du);
    int getDuration();
    void setAssignmentTime(int at);
    int getAssignmentTime();
    void setResource(Resource*);
    Resource* GetResource();

    virtual char GetType() = 0;

    virtual bool canAssign(Resource* r, int currentTime) = 0;

    virtual void moveToWait(Patient* p, Scheduler* scheduler) = 0;

    virtual ~Treatment() {}
};

