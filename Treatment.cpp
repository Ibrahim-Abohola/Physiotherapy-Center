#include "Treatment.h"

Treatment::Treatment(int d) : duration(d), AssignmentTime(-1){}

void Treatment::setDuration(int du)
{
	if (du > 0)
	{
		duration = du;
	}
}

int Treatment::getDuration()
{
	return duration;
}

void Treatment::setAssignmentTime(int at)
{
	if (at > 0)
	{
		AssignmentTime = at;
	}
}

int Treatment::getAssignmentTime()
{
	return AssignmentTime;
}

void Treatment::setResource(Resource* r) {
	AssignedResource = r;
}

Resource * Treatment::GetResource() {
	return AssignedResource;
}
