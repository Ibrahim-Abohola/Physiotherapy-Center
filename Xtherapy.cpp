#include "Xtherapy.h"
#include "Patient.h"
#include "Scheduler.h"

Xtherapy::Xtherapy(int d) : Treatment(d) {}


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
