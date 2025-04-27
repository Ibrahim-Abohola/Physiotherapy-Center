#include "Resource.h"
#include <iostream>


Resource::Resource(string type) : resourceType(type), isAvailable(true){}

bool Resource::allocate()
{
    return false;
}

void Resource::release()
{
}


bool Resource::checkAvailability()
{
    return isAvailable;
}
bool Resource::IsFull()
{
	return false;
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

int Resource::getID() const
{
	return ID;
}
