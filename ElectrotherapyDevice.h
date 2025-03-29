#pragma once
#include "Resource.h"
class ElectrotherapyDevice : public Resource 
{
public:
    ElectrotherapyDevice(int id);

    bool allocate();

    void release();
};
