#pragma once
#include <fstream>
#include "ArrayStack.h"
#include "EU_Queue.h"
#include "X_Queue.h"
#include "Early_PriQueue.h"
#include "Patient.h"

class UI;

class Scheduler {
	LinkedQueue<Patient*> All_Patients;
	Early_priQueue<Patient*> EarlyList;
	priQueue<Patient*> LateList;
	X_Queue<Patient*> X_Waiting;
	EU_Queue<Patient*> U_Waiting;
	EU_Queue<Patient*> E_Waiting;
	LinkedQueue<Resource*> AvailE_Devices;
	LinkedQueue<Resource*> AvailU_Devices;
	LinkedQueue<Resource*> AvailX_Rooms;
	priQueue<Patient*> In_Treatment;
	ArrayStack<Patient*> FinishList;
	int TP; //total number of patients
	int TWT;  //total waiting time of all patients 
	int TTT; //total treatment time of all patients 
	int Timestep; // the current time step &&  total timesteps at the end
	int Total_RPatients;  // total number of r patients
	int Total_NPatients;   // total number of n patients
	int TWT_R;  // total waiting time for R  patients
	int TWT_N;  // total waiting time for N patients
	int TTT_R; //  total treatment time for R patients
	int TTT_N; //  total treatment time for N patients
	int AC_Cancellations; // number of accepted cancellations
	int AC_Rescheduling; // number of accepted rescheduling

	int Early_Patients; // number of early patients
	int Late_Patients; // number of late patients

	int Total_Penality; // average number of timesteps of the late penality applied for the late patient
	int pCancel; //probability of cancellation
	int pResch; // probability of rescheduling

public:
	Scheduler();
	void AddPatient(Patient*& p);
	void AddToEarly(Patient*& p);
	void AddToLate(Patient*& p);
	void AddToU_Waiting(Patient*& p);
	void AddToX_Waiting(Patient*& p);
	void AddToE_Waiting(Patient*& p);
	void AddToU_Device(Resource*& resource);
	void AddToE_Device(Resource*& resource);
	void AddToX_Room(Resource*& resource);
	void AddToIn_Treatment(Patient*& p);
	void AddToFinishLIst(Patient*& p);
	void FromAllto();
	void FromEarlyLateto();
	void HandleRPatient(Patient*);
	void AssignE(); //Mego added
	void AssignU(); //Mego added
	void AssignX(); //Mego added
	void FromInTreatTo();
	void LoadData(string in); // to read the input file and initialize lists
	void Cancellation(); // to handle cancellations
	void reschedule();  // to handle rescheduling
	void simulate(); // to process each time step and make the needed transitions
	int GetTWT() const;
	int GetTotal_NPatients() const;
	int GetTotal_RPatients() const;
	double GetAvgWT_R() const;
	double GetAvgWT_N() const;
	double GetAvgTT_R() const;
	double GetAvgTT_N() const;
	double GetAvgTWT() const;
	double GetAvgTTT() const;

	double GetPer_cancellation() const;
	double GetPer_rescheduling() const;
	double GetPer_Early() const;
	double GetPer_Late() const;
	double GetAvgPenality() const;

	int GetTimestep() const;  //ebra added
	int GetTP() const;		  //ebra added
	int GetTTT() const;		  //ebra added
	void SetTTT(int t);

	LinkedQueue<Patient*>& Get_All_Patients();    //ebra added
	Early_priQueue<Patient*>& Get_Early_List();	  //ebra added
	priQueue<Patient*>& Get_Late_List();		  //ebra added
	X_Queue<Patient*>& Get_X_Waiting();		      //ebra added
	EU_Queue<Patient*>& Get_U_Waiting();		  //ebra added
	EU_Queue<Patient*>& Get_E_Waiting();		  //ebra added
	priQueue<Patient*>& Get_In_Treatment();		  //ebra added
	ArrayStack<Patient*>& Get_Finish_List();	  //ebra added

	LinkedQueue<Resource*>& Get_AvailE_Devices(); //ebra added
	LinkedQueue<Resource*>& Get_AvailU_Devices(); //ebra added
	LinkedQueue<Resource*>& Get_AvailX_Rooms();	  //ebra added


};