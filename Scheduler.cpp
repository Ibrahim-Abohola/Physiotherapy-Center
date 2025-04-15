#include "Scheduler.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

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


int Scheduler::GetTimestep() const{
	return Timestep;
}

int Scheduler::GetTP() const
{
	return TP;
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
	cout << "Enter the name of the input file"<<endl;
	string in;
	cin >> in;
	in += ".txt";
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
		Input >> type;
		Input >> pt >> vt >> nt;
		Patient* P = new Patient(type, pt, vt);
		while (nt--) {
			int duration;
			Input >> type;
			Input >> duration;
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
	
bool Scheduler::Cancellation(Patient& p) {
	LinkedQueue<Patient*> tempQueue;
	bool found = false;
	Patient* current;

	while (!All_Patients.isEmpty()) {
		All_Patients.dequeue(current);
		if (current->GetID() == p.GetID()) {
			found = true;
			delete current; // Optional: free memory if needed
			continue;       // skip enqueueing this one
		}
		tempQueue.enqueue(current);
	}

	// Move items back to original queue
	while (!tempQueue.isEmpty()) {
		tempQueue.dequeue(current);
		All_Patients.enqueue(current);
	}

	return found;
}

bool Scheduler::reschedule(Patient& p){
	srand(time(0));
	int nt = rand() % (All_Patients.GetCount());

	LinkedQueue<Patient*> tempQueue;
	bool found = false;
	Patient* current;

	while (!All_Patients.isEmpty()) {
		All_Patients.dequeue(current);
		if (current->GetID() == p.GetID()) {
			found = true;
			p.SetPT(nt) ;
			continue;       // skip enqueueing this one
		}
		tempQueue.enqueue(current);
	}

	// Move items back to original queue
	while (!tempQueue.isEmpty()) {
		tempQueue.dequeue(current);
		All_Patients.enqueue(current);
	}

	return found;
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


// ======================= Patient Queues =======================

LinkedQueue<Patient*>& Scheduler::Get_All_Patients() {
	return All_Patients;
}

Early_priQueue<Patient*>& Scheduler::Get_Early_List() {
	return EarlyList;
}

priQueue<Patient*>& Scheduler::Get_Late_List() {
	return LateList;
}

X_Queue<Patient*>& Scheduler::Get_X_Waiting() {
	return X_Waiting;
}

SortedQueue<Patient*>& Scheduler::Get_U_Waiting() {
	return U_Waiting;
}

SortedQueue<Patient*>& Scheduler::Get_E_Waiting() {
	return E_Waiting;
}

priQueue<Patient*>& Scheduler::Get_In_Treatment() {
	return In_Treatment;
}

ArrayStack<Patient*>& Scheduler::Get_Finish_List() {
	return FinishList;
}

// ======================= Resource Queues =======================

LinkedQueue<Resource*>& Scheduler::Get_AvailE_Devices() {
	return AvailE_Devices;
}

LinkedQueue<Resource*>& Scheduler::Get_AvailU_Devices() {
	return AvailU_Devices;
}

LinkedQueue<Resource*>& Scheduler::Get_AvailX_Rooms() {
	return AvailX_Rooms;
}
