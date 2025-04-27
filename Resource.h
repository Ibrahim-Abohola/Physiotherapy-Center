#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <string>

class Resource
{
    string resourceType;
    bool isAvailable;
protected:
    int ID;

public:

    Resource(string type);

    virtual bool allocate();

    virtual void release();

    virtual bool checkAvailability();

	virtual bool IsFull();

    string getResourceType() const;

    virtual void print(ostream& os) const;

    int getID() const;

    friend ostream& operator<<(ostream& os, const Resource& res);

    virtual ~Resource() {}
};