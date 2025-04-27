#pragma once
#include "Resource.h"

class E_Device : public Resource
{
    static int EID;
public:
    E_Device();

  

    void print(ostream& os) const override;

};
