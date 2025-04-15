#include "Scheduler.h"
#include <fstream>

Scheduler::Scheduler() :
	TWT(0), Timestep(0), Total_NPatients(0), Total_RPatients(0), AC_Cancellations(0), AC_Rescheduling(0), AvgPenality(0),
	AvgTT_N(0), AvgTT_R(0), AvgWT_N(0), AvgWT_R(0),Per_cancellation(0),Per_Rescheduling(0), Per_Early(0), Per_Late(0)
{ }


int Scheduler::GetTotal_NPatients() const {
	return Total_NPatients;
}

int Scheduler::GetTotal_RPatients() const {
	return Total_RPatients;
}

int Scheduler::GetTWT() const {
	return TWT;
}


double Scheduler::GetAvgTT_N() const {
	return AvgTT_N;
}

double Scheduler::GetAvgTT_R() const {
	return AvgTT_R;
}

double Scheduler::GetAvgWT_R() const {
	return AvgWT_R;
}
double Scheduler::GetAvgWT_N() const {
	return AvgWT_N;
}

double Scheduler::GetAvgPenality() const {
	return AvgPenality;
}

double Scheduler::GetPer_cancellation() const {
	return Per_cancellation;
}

double Scheduler::GetPer_rescheduling() const {
	return Per_Rescheduling;
}


double Scheduler::GetPer_Early() const {
	return Per_Early;
}

double Scheduler::GetPer_Late() const {
	return Per_Late;
}
void Scheduler::SetTimestep(int t) {
	if (t > Timestep)
		Timestep = t;
}

void Scheduler::AddPatient(Patient* p) {
	p->UpdateStatus("Idle");
	All_Patients.enqueue(p);
}

void Scheduler::AddToEarly(Patient* p) {

	p->UpdateStatus("Early");
	EarlyList.enqueue(p,-(p->GetPT()));

}


void Scheduler::AddToLate(Patient* p) {

	p->UpdateStatus("Late");
	LateList.enqueue(p, -(p->GetVT() + p->GetPenality()));

}

void Scheduler::AddToU_Waiting(Patient * p) {
	if (p->GetStatus() == "Early")
		U_Waiting.enqueue(p);
	else
		U_Waiting.InsertSorted(p);
	p->UpdateStatus("Wait");
}

void Scheduler::AddToX_Waiting(Patient* p) {
	if (p->GetStatus() == "Early")
		X_Waiting.enqueue(p);
	else
		X_Waiting.InsertSorted(p);
	p->UpdateStatus("Wait");

}

void Scheduler::AddToE_Waiting(Patient* p) {
	if (p->GetStatus() == "Early")
		E_Waiting.enqueue(p);
	else
		E_Waiting.InsertSorted(p);
	p->UpdateStatus("Wait");

}

void Scheduler::AddToU_Device(Resource* resource) {
	AvailU_Devices.enqueue(resource);
}

void Scheduler::AddToE_Device(Resource* resource) {
	AvailE_Devices.enqueue(resource);
}


void Scheduler::AddToX_Room(Resource* resource) {
	AvailX_Rooms.enqueue(resource);
}

void Scheduler::AddToIn_Treatment(Patient* p) {
	if (p->GetCurrentTreatment())
		In_Treatment.enqueue(p, -(p->GetCurrentTreatment()->getAssignmentTime() + p->GetCurrentTreatment()->getDuration()));
	p->UpdateStatus("Serv");
}

void Scheduler::AddToFinishLIst(Patient* p) {
	FinishList.push(p);
}

void Scheduler::LoadData() {

	ifstream Input;
	cout << "Enter the name of the input file";
	string in;
	cin >> in;
	in += "txt";
	Input.open(in);
	int n;
	Input >> n;
	while (n--) {
		Resource* newresource = new E_Device;
		AvailE_Devices.enqueue(newresource);
	}
	Input >> n;
	while (n--) {
		Resource* newresource = new U_Device;
		AvailU_Devices.enqueue(newresource);
	}
	Input >> n;
	while (n--) {
		int capacity;
		Input >> capacity;
		Resource* newresource = new GymRoom(capacity);
		AvailX_Rooms.enqueue(newresource);
	}
	Input >> pCancel >> pResch;
	Input >> TP;
	n = TP;
	while (n--) {
		char type;
		int pt,vt,nt;
		cin >> type;
		cin >> pt >> vt >> nt;
		Patient* P = new Patient(type, pt, vt);
		while (nt--) {
			int duration;
			cin >> type;
			cin >> duration;
			Treatment * T;
			if (type == 'E')
				T = new ETherapy(duration);
			else if (type == 'U')
				T = new Utherapy(duration);
			else if (type == 'X')
				T = new Xtherapy(duration);
			else
				T = NULL;
			if (T)
				P->AddTreatment(T);
		}
		All_Patients.enqueue(P);

	}

}

void Scheduler::Cancellation() 
{
	Patient* P;
	if (X_Waiting.Cancel2(P))
		FinishList.push(P);
}

void Scheduler::reschedule() 
{
	Patient* P;
	if(EarlyList.Reschedule2(P))
	{
		int newPT = rand() % (P->GetPT() / 2) + P->GetPT() + 1;
		P->ModifyPT(newPT);
		AddToEarly(P);
	}
	
}

void Scheduler::simulate(){

	do {
		Patient* P;
		All_Patients.peek(P);
		if (P && P->GetVT() == Timestep)
		{
			All_Patients.dequeue(P);
		}
		else
			Timestep++;

	} while (FinishList.GetCount() != TP);

}

void Scheduler::collectStatistics() 
{

}