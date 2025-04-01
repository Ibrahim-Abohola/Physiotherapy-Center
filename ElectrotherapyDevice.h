#pragma once
#include "Resource.h"

class ElectrotherapyDevice : public Resource
{
    static int EID;
public:
    ElectrotherapyDevice();

    int getEID() const;

    bool allocate(int& deviceID);

    void release();
};
