#pragma once
#include"Resource.h"
class Treatment
{

    int duration;

    int assignmentTime;

    Resource* assignedResource;


public:
    Treatment(int d);
    void setDuration(int du);
    int getDuration();
    void setAssignmentTime(int at);
    int getAssignmentTime();
};

