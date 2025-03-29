#include "Treatment.h"

Treatment::Treatment(int d) : duration(d), assignmentTime(-1), assignedResource(nullptr) {}

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
		assignmentTime = at;
	}
}

int Treatment::getAssignmentTime()
{
	return assignmentTime;
}
