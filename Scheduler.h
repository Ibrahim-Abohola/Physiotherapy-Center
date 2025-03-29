#pragma once

#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "SortedQueue.h"
#include "priQueue.h"
#include "X_Queue.h"
#include "Early_PriQueue.h"
#include "Patient.h"


class Scheduler {
	LinkedQueue<Patient*> All_Patients;
	Early_priQueue<Patient*> EarlyList;
	priQueue<Patient*> LateList;
	X_Queue<Patient*> X_Waiting;
	SortedQueue<Patient*> U_Waiting;
	SortedQueue<Patient*> E_Waiting;
	LinkedQueue<Resource*> E_devices;
	LinkedQueue<Resource*> U_devices;
	LinkedQueue<Resource*> X_Rooms;
	priQueue<Patient*> In_Treatment;
	ArrayStack<Patient*> FinishList;
public:

};