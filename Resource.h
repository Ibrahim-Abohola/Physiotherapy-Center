#pragma once
using namespace std;
#include <string>

class Resource 
{
    string resourceType;
    int resourceID;
    bool isAvailable;

public:
    Resource(string type, int id);

    virtual bool allocate() = 0;
    virtual void release() = 0;

    virtual bool checkAvailability() const;
    void setAvailability(bool av);

    string getResourceType() const;

    int getResourceID() const;

    virtual ~Resource() {}
};