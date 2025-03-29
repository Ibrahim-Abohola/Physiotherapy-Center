#pragma once
#pragma once
#include "LinkedQueue.h"

class Patient {
	char Type; // type of the patient N or R 
	static int ID; 
	int VT; // arrival time
	int PT; // appointment time
	int WT; // total waiting time of the patient
	int FT;  // finish time of the patient
	int TT; // total treatment time of the patient
	string Status; //status of the patient 
public:
	Patient(char type, int pt, int vt);
	void AddTreatment();
	void RemoveTreatment();
	void UpdateStatus(string s);
	void SetFT(int t);
	void UpdateWT(int t);
	void UpdateTT(int t);
	static int GetID();
	int GetFT() const;
	int GetVT() const;
	int GetPT() const;
	int GetWT() const;
	int GetTT() const;
	char GetType() const;
	string GetStatus() const;
	bool operator<=(Patient*& p);
	bool operator>=(Patient*& p);
};