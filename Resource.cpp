#include "Resource.h"
#include <iostream>

Resource::Resource(string type, int id) : resourceType(type), resourceID(id), isAvailable(true) {}

bool Resource::allocate(int& deviceID)
{
    cout << "something went wrong! you are in class Resource itself";
    return false;
}

bool Resource::allocate(int& room, int& device)
{
    cout << "something went wrong! you are in class Resource itself";
    return false;
}

void Resource::release()
{
    cout << "something went wrong! you are in class Resource itself";
}

void Resource::release(int deviceID)
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

int Resource::getResourceID() const
{
    return resourceID;
}
