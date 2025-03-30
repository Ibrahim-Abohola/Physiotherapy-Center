#pragma once
#include "Resource.h"

class UltrasoundDevice : public Resource
{
    static int UID;
public:
    UltrasoundDevice();

    int getUID() const;

    bool allocate(int& deviceID);

    void release();
};

