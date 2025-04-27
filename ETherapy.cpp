#include "ETherapy.h"
#include "Patient.h"
#include "Scheduler.h"

ETherapy::ETherapy(int d) : Treatment(d) {}

bool ETherapy::canAssign(Resource* r, int currentTime)
{
    if (r) {
		AssignedResource = r;
		AssignmentTime = currentTime;
		return true;
    }
    return false;
}

void ETherapy::moveToWait(Patient* p, Scheduler* scheduler)
{
    if (p && scheduler) 
    {
        scheduler->AddToE_Waiting(p);
    }
}

char ETherapy::GetType()
{
	return 'E';
}