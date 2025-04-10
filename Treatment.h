#pragma once
#include"Resource.h"
#include"LinkedQueue.h"

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

    virtual ~Treatment() {}
};

