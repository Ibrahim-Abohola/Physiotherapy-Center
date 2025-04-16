#pragma once
using namespace std;
#include <string>

class Resource
{
    string resourceType;
    bool isAvailable;

public:

    Resource(string type);

    virtual bool allocate();

    virtual void release();

    virtual bool checkAvailability();
    void setAvailability(bool av);

    string getResourceType() const;

    virtual ~Resource() {}
};