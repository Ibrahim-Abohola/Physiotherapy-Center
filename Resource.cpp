#include "Resource.h"

Resource::Resource(string type, int id) : resourceType(type), resourceID(id), isAvailable(true) {}

bool Resource::checkAvailability() const
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
