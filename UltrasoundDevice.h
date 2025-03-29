#pragma once
#include "Resource.h"

class UltrasoundDevice : public Resource 
{
public:
    UltrasoundDevice(int id);

    bool allocate();

    void release();
};

