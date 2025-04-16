#pragma once
#include "Resource.h"

class U_Device : public Resource
{
    static int UID;
    int ID;
public:
    U_Device();

    int getUID() const;

    bool allocate();

    void release();

    void print(ostream& os) const override;
};

