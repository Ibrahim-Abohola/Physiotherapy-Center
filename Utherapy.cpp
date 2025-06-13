#include "Utherapy.h"
#include "Patient.h"
#include "Scheduler.h"

Utherapy::Utherapy(int d) : Treatment(d) {}


void Utherapy::moveToWait(Patient* p, Scheduler* scheduler)
{
    if (p && scheduler)
    {
        scheduler->AddToU_Waiting(p);
    }
}

char Utherapy::GetType()
{
	return 'U';
}