#include "LinkedQueue.h"
#include "priQueue.h"
#include "EU_Queue.h"
#include "Scheduler.h"

int main() {

	srand(time(NULL));
	Scheduler scheduler;
	scheduler.simulate();
	return 0;
}