#include "ETherapy.h"
#include "Patient.h"
#include "Scheduler.h"

ETherapy::ETherapy(int d) : Treatment(d) {}


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