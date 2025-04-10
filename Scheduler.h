#pragma once
#include <fstream>
#include "ArrayStack.h"
#include "SortedQueue.h"
#include "priQueue.h"
#include "X_Queue.h"
#include "Early_PriQueue.h"
#include "Patient2.h"


class Scheduler {
	LinkedQueue<Patient*> All_Patients;
	Early_priQueue<Patient*> EarlyList;
	priQueue<Patient*> LateList;
	X_Queue<Patient*> X_Waiting;
	SortedQueue<Patient*> U_Waiting;
	SortedQueue<Patient*> E_Waiting;
	LinkedQueue<Resource*> AvailE_Devices;
	LinkedQueue<Resource*> AvailU_Devices;
	LinkedQueue<Resource*> AvailX_Rooms;
	priQueue<Patient*> In_Treatment;
	ArrayStack<Patient*> FinishList;
	int TP; //total number of patients
	int TWT;  //total waiting time of all patients 
	int Timestep; // the current time step &&  total timesteps at the end
	int Total_RPatients;  // total number of r patients
	int Total_NPatients;   // total number of n patients
	double AvgWT_R;  // average total waiting time for R  patients
	double AvgWT_N;  //average total waiting time for N patients
	double AvgTT_R; // average total treatment time for R patients
	double AvgTT_N; // average total treatment time for N patients
	int AC_Cancellations; // number of accepted cancellations
	int AC_Rescheduling; // number of accepted rescheduling
	double Per_cancellation; // percentage of accepted cancellations
	double Per_Rescheduling;//percentage of accepted rescheduling
	double Per_Early; // percentage of early patients
	double Per_Late; // percentage of late patients
	double AvgPenality; // average number of timesteps of the late penality applied for the late patient
	int pCancel; //probability of cancellation
	int pResch; // probability of rescheduling
public:
	Scheduler();
	void AddPatient(Patient* p);
	void AddToEarly(Patient* p);
	void AddToLate(Patient* p);
	void AddToU_Waiting(Patient* p);
	void AddToX_Waiting(Patient* p);
	void AddToE_Waiting(Patient* p);
	void AddToU_Device(Resource* resource);
	void AddToE_Device(Resource* resource);
	void AddToX_Room(Resource* resource);
	void AddToIn_Treatment(Patient* p);
	void AddToFinishLIst(Patient* p);
	void LoadData(); // to read the input file and initialize lists
	void Cancellation(); // to handle cancellations
	void reschedule();  // to handle rescheduling
	void ProcessTimestep(); // to process each time step and make the needed transitions
	void collectStatistics(); // collect statistics when all patients finish
	void SetTimestep(int t); 
	int GetTWT() const;
	int GetTotal_NPatients() const;
	int GetTotal_RPatients() const;
	double GetAvgWT_R() const;
	double GetAvgWT_N() const;
	double GetAvgTT_R() const;
	double GetAvgTT_N() const;
	double GetPer_cancellation() const;
	double GetPer_rescheduling() const;
	double GetPer_Early() const;
	double GetPer_Late() const;
	double GetAvgPenality() const;


};