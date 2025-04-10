#pragma once
using namespace std;
#include <string>

class Resource
{
    string resourceType;
    bool isAvailable;

public:
    Resource();
    Resource(string type, bool isAvailable);

    virtual bool allocate();

    virtual void release();

    virtual bool checkAvailability();
    void setAvailability(bool av);

    string getResourceType() const;

    virtual ~Resource() {}
};