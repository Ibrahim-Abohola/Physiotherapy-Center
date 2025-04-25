#pragma once
#include "Resource.h"

class E_Device : public Resource
{
    static int EID;
    int ID;
public:
    E_Device();

    int getEID() const;

    void print(ostream& os) const override;

};
