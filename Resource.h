#pragma once
using namespace std;
#include <string>

class Resource
{
    string resourceType;
    bool isAvailable;

public:
    Resource(string type, bool isAvailable);

    virtual bool allocate(int& deviceID);

    virtual void release();

    virtual bool checkAvailability();
    void setAvailability(bool av);

    string getResourceType() const;

    virtual ~Resource() {}
};