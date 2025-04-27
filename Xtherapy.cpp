#include "Xtherapy.h"
#include "Patient.h"
#include "Scheduler.h"

Xtherapy::Xtherapy(int d) : Treatment(d) {}

bool Xtherapy::canAssign(Resource * r, int currentTime)
{
    if (r && r->allocate()) {
        AssignedResource = r;
        AssignmentTime = currentTime;
        return true;
    }
    return false;

}

void Xtherapy::moveToWait(Patient* p, Scheduler* scheduler)
{
    if (p && scheduler)
    {
        scheduler->AddToX_Waiting(p);
    }
}
char Xtherapy::GetType()
{
	return 'X';
}
