#pragma once
#include "Resource.h"
class ElectrotherapyDevice : public Resource 
{
public:
    ElectrotherapyDevice();
    ElectrotherapyDevice(int id);

    bool allocate(int& deviceID);

    void release();
};
