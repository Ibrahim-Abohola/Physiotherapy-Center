#pragma once
#include "Resource.h"

class E_Device : public Resource
{
    static int EID;
public:
    E_Device();

    int getEID() const;

    bool allocate();

    void release();
};
