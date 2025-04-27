#pragma once
#include "Resource.h"
#include "LinkedQueue.h"

class GymRoom : public Resource {
private:
    static int RID;
    int maxRoomSize;
    int capacity;

public:
    
    GymRoom(int roomSize);


    bool allocate();

    void release();

    virtual bool checkAvailability() const;
    
    virtual bool IsFull() override;

    int getMaxRoomSize() const;

    int getCurrentCapacity() const;

    void print(ostream& os) const override;
};