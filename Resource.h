#pragma once
#include <iostream>
#include <fstream>
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

    virtual void print(ostream& os) const;

    friend ostream& operator<<(ostream& os, const Resource& res);

    virtual ~Resource() {}
};