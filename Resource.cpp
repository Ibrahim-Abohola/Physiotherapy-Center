#include "Resource.h"
#include <iostream>


Resource::Resource(string type, bool isAvailable) : resourceType(type), isAvailable(true){}

bool Resource::allocate()
{
    cout << "something went wrong! you are in class Resource itself";
    return false;
}

void Resource::release()
{
    cout << "something went wrong! you are in class Resource itself";
}


bool Resource::checkAvailability()
{
    return isAvailable;
}

void Resource::setAvailability(bool av)
{
    isAvailable = av;
}

string Resource::getResourceType() const
{
    return resourceType;
}
