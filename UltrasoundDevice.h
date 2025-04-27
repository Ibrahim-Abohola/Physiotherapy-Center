#pragma once
#include "Resource.h"

class U_Device : public Resource
{
    static int UID;
public:
    U_Device();


    void print(ostream& os) const override;
};

