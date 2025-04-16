#include "Utherapy.h"
#include "Patient.h"
#include "Scheduler.h"

Utherapy::Utherapy(int d) : Treatment(d) {}

bool Utherapy::canAssign(Resource* r, int currentTime)
{
    return false;

}

void Utherapy::moveToWait()
{
    return;
}