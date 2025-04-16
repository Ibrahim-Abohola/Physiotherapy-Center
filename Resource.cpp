#include "Resource.h"
#include <iostream>


Resource::Resource(string type) : resourceType(type), isAvailable(true){}

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

ostream& operator<<(ostream& os, const Resource& res) {
    res.print(os);
    return os;
}
void Resource::print(ostream& os) const {
}
