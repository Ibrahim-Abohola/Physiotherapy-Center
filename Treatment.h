#pragma once
#include"Resource.h"
#include"LinkedQueue.h"
#include"Patient2.h"
#include"Scheduler.h"

class Treatment
{

    int duration;
    
protected:
    int AssignmentTime;
    Resource* AssignedResource;

public:
    Treatment(int d);
    void setDuration(int du);
    int getDuration();
    void setAssignmentTime(int at);
    int getAssignmentTime();
    void setResource(Resource*);
    Resource* GetResource();

    virtual bool canAssign(LinkedQueue<Resource* >& resources, int currentTime, int& ID)=0;

    virtual void moveToWait(Patient* p, Scheduler* scheduler)=0;

    virtual ~Treatment() {}
};

