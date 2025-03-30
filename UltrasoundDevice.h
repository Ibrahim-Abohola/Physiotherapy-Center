#pragma once
#include "Resource.h"

class UltrasoundDevice : public Resource 
{
public:
    UltrasoundDevice();
    UltrasoundDevice(int id);

    bool allocate(int& deviceID);

    void release();
};

