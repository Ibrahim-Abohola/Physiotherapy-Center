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

    virtual bool allocate(int &deviceID);
    virtual bool allocate(int& room, int& device);

    virtual void release();
    virtual void release(int deviceID);

    virtual bool checkAvailability();
    void setAvailability(bool av);

    string getResourceType() const;

    int getResourceID() const;

    virtual ~Resource() {}
};