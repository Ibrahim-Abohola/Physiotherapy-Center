#include "Xtherapy.h"
#include "Patient.h"
#include "Scheduler.h"

Xtherapy::Xtherapy(int d) : Treatment(d) {}

bool Xtherapy::canAssign(Resource * r, int currentTime)
{
    return false;

}

void Xtherapy::moveToWait()
{
    return;
}
