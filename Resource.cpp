#include "Resource.h"
#include <iostream>


Resource::Resource(string type) : resourceType(type), isAvailable(true){}

bool Resource::allocate()
{
    if (checkAvailability()) 
    {
        setAvailability(false);
        return true;
    }
    return false;
}

void Resource::release()
{
    setAvailability(true);
}


bool Resource::checkAvailability()
{
    return isAvailable;
}

void Resource::setAvailability(bool av)
{
    isAvailable = av;
}

void Resource::print(ostream& os) const {
}


ostream& operator<<(ostream& os, const Resource& res) {
    res.print(os);
    return os;
}

string Resource::getResourceType() const
{
    return resourceType;
}
