#pragma once
#include "LinkedQueue.h"
#include "Xtherapy.h"
#include "ETherapy.h"
#include "Utherapy.h"

class Patient {
	char Type; // type of the patient N or R 
	static int pID;
	int ID;
	int VT; // arrival time
	int PT; // appointment time
	int WT; // total waiting time of the patient
	int FT;  // finish time of the patient
	int TT; // total treatment time of the patient
	int Penality; // applied penality in case of late patient
	string Status; //status of the patient 
	LinkedQueue<Treatment*> TreatmentList;

	bool isCanceled;
	int Reschedules;

public:
	Patient(char type, int pt, int vt);
	void AddTreatment(Treatment* treatment);
	void RemoveTreatment(Resource*&);
	void UpdateStatus(string s);
	void SetFT(int t);
	void ModifyPT(int t);
	void SetWT(int t);
	void UpdateTT(int t);
	int GetID() const;
	int GetFT() const;
	int GetVT() const;
	int GetPT() const;
	int GetWT() const;
	int GetTT() const;
	int GetPenality() const;
	Treatment* GetCurrentTreatment() const;
	char GetType() const;
	string GetStatus() const;
	bool operator<=(Patient p);
	bool operator>=(Patient p);
	bool operator<(Patient p);
	bool operator>(Patient p);
	int operator!(); // overloading operator to get curr tretment duration for computing TL of wait lists
	bool operator~(); // overloading operator to check if the curr treatment is the last treatment for the cancel function
	bool operator&(); // to make sure that the patient is not rescheduled more than once
	friend ostream& operator<<(ostream& os, const Patient& res);

	bool GetisCanceled();
	bool GetisRscheduled();
	void SetisCanceled();
	void UpdateRschedules();


};