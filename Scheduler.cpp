#include "Scheduler.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "UI2.h"

Scheduler::Scheduler() :
	TWT(0), Timestep(0), Total_NPatients(0), Total_RPatients(0), AC_Cancellations(0), AC_Rescheduling(0), AvgPenality(0),
	AvgTT_N(0), AvgTT_R(0), AvgWT_N(0), AvgWT_R(0),Per_cancellation(0),Per_Rescheduling(0), Per_Early(0), Per_Late(0)
{ }


int Scheduler::GetTimestep() const
{
	return Timestep;
}
int Scheduler::GetTP() const
{
	return TP;
}

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

void Scheduler::AddPatient(Patient*& p) {
	All_Patients.enqueue(p);
}

void Scheduler::AddToEarly(Patient*& p) {

	p->UpdateStatus("EARLY");
	EarlyList.enqueue(p,-(p->GetPT()));

}


void Scheduler::AddToLate(Patient*& p) {

	p->UpdateStatus("LATE");
	LateList.enqueue(p, -(p->GetVT() + p->GetPenality()));

}

void Scheduler::AddToU_Waiting(Patient *& p) {
	if (p->GetStatus() == "EARLY" || p->GetStatus() == "IDLE")
		U_Waiting.enqueue(p);
	else
		U_Waiting.InsertSorted(p);
	p->UpdateStatus("WAIT");
}

void Scheduler::AddToX_Waiting(Patient*& p) {
	if (p->GetStatus() == "EARLY" || p->GetStatus() == "IDLE")
		X_Waiting.enqueue(p);
	else
		X_Waiting.InsertSorted(p);
	p->UpdateStatus("WAIT");

}

void Scheduler::AddToE_Waiting(Patient*& p) {
	if (p->GetStatus() == "EARLY" || p->GetStatus() == "IDLE")
		E_Waiting.enqueue(p);
	else
		E_Waiting.InsertSorted(p);
	p->UpdateStatus("WAIT");

}

void Scheduler::AddToU_Device(Resource *& resource) {
	AvailU_Devices.enqueue(resource);
}

void Scheduler::AddToE_Device(Resource *& resource) {
	AvailE_Devices.enqueue(resource);
}


void Scheduler::AddToX_Room(Resource *& resource) {
	AvailX_Rooms.enqueue(resource);
}

void Scheduler::AddToIn_Treatment(Patient*& p) {
	if (p->GetCurrentTreatment())
		In_Treatment.enqueue(p, -(p->GetCurrentTreatment()->getAssignmentTime() + p->GetCurrentTreatment()->getDuration()));
	p->UpdateStatus("SERV");
}

void Scheduler::AddToFinishLIst(Patient*& p) {
	p->UpdateStatus("FNSH");
	FinishList.push(p);
}

void Scheduler::LoadData(string in) {

	ifstream Input;
	Input.open(in);
	int n;
	Input >> n;
	while (n--)
	{
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
	if (X_Waiting.Cancel(true,P))
		AddToFinishLIst(P);
}

void Scheduler::reschedule()
{
	Patient* P;
	if (EarlyList.Reschedule(P))
	{
		int newPT = rand() % (P->GetPT() / 2) + P->GetPT() + 1;
		P->ModifyPT(newPT);
		AddToEarly(P);
	}
}

void Scheduler::FromAllto()
{
	while (!All_Patients.isEmpty())
	{
		Patient* P;
		All_Patients.peek(P);
		if (P->GetVT() == Timestep)
		{
			All_Patients.dequeue(P);
			if (P->GetVT() < P->GetPT())
				AddToEarly(P);
			else if (P->GetVT() > P->GetPT())
				AddToLate(P);
			else
			{
				if (P->GetType() == 'N')
					P->GetCurrentTreatment()->moveToWait(P, this);
				else
					HandleRPatient(P);
			}

		}
		else
			break;
	}

}

void Scheduler::FromEarlyLateto()
{
	while (!EarlyList.isEmpty())
	{
		Patient* p;
		int pri;
		EarlyList.peek(p,pri);
		if (p->GetPT() == Timestep)
		{
			EarlyList.dequeue(p, pri);
			if (p->GetType() == 'N')
				p->GetCurrentTreatment()->moveToWait(p, this);
			else
				HandleRPatient(p);
		}
		else
			break;
	}
	while (!LateList.isEmpty())
	{
		Patient* p;
		int pri;
		LateList.peek(p, pri);
		pri *= -1;
		if (pri == Timestep)
		{
			LateList.dequeue(p, pri);
			if (p->GetType() == 'N')
				p->GetCurrentTreatment()->moveToWait(p, this);
			else
				HandleRPatient(p);
		}
		else
			break;
	}
}

void Scheduler::FromInTreatTo()
{
	while (!In_Treatment.isEmpty())
	{
		Patient* p;
		int pri;
		In_Treatment.peek(p, pri);
		pri *= -1;
		if (pri == Timestep)
		{
			In_Treatment.dequeue(p, pri);
			p->UpdateTT(p->GetCurrentTreatment()->getDuration());
			Resource* r;
			p->RemoveTreatment(r);
			if (r->getResourceType() == "E_Device")
				AvailE_Devices.enqueue(r);
			else if (r->getResourceType() == "U_Device")
				AvailU_Devices.enqueue(r);
			else if (r->getResourceType() == "GymRoom")
			{
				if (!r->checkAvailability())
					AvailX_Rooms.enqueue(r);
			}
			r->release();
			if (!p->GetCurrentTreatment())
			{
				AddToFinishLIst(p);
			}
			else
			{
				if (p->GetType() == 'N')
					p->GetCurrentTreatment()->moveToWait(p, this);
				else
					HandleRPatient(p);
			}
		}
		else
			break;
	}
}


void Scheduler::HandleRPatient(Patient * p)
{
	priQueue<char> temp;
	temp.enqueue('X', -X_Waiting.CalcTreatmentLatency());
	temp.enqueue('E', -E_Waiting.CalcTreatmentLatency());
	temp.enqueue('U', -U_Waiting.CalcTreatmentLatency());
	int pri;
	char best;
	temp.dequeue(best, pri);
	int count = 1;
	while (count)
	{
		Treatment* t = p->GetCurrentTreatment();
		if (t->GetType() == best)
			break;
		else
		{
			if (count < 3)
				count++;
			else {
				temp.dequeue(best, pri);
				count = 1;
			}
			Resource* r;
			p->RemoveTreatment(r);
			p->AddTreatment(t);
		}
	}
	p->GetCurrentTreatment()->moveToWait(p, this);
}

void Scheduler::simulate(){

	UI ui(this);
	string in = ui.GetInputFile();
	this->LoadData(in);

	do {

		this->FromAllto();
		this->FromEarlyLateto();
		///
		///
		this->FromInTreatTo();


		cin.get();
		ui.OutputScreen();
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

EU_Queue<Patient*>& Scheduler::Get_U_Waiting() {
	return U_Waiting;
}

EU_Queue<Patient*>& Scheduler::Get_E_Waiting() {
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
