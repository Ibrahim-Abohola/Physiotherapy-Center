#include "Patient.h"

int Patient::ID = 0;

Patient::Patient(char type, int pt, int vt) :
	Type(type), PT(pt), VT(vt)
{
	ID++;
	WT = 0;
	FT = 0;
	TT = 0;
	if (PT < VT) {
		UpdateStatus("Late");
		Penality = (VT - PT) / 2;
	}
	else {
		UpdateStatus("Early");
		Penality = 0;
	}
}

void Patient::UpdateStatus(string s) {
	Status = s;
}

void Patient::AddTreatment(Treatment * treatment) 
{
	TreatmentList.enqueue(treatment);
}

Treatment * Patient::RemoveTreatment()
{
	Treatment* treatment;
	TreatmentList.dequeue(treatment);
	return treatment;
}

void Patient::UpdateWT(int t) {
	if (t > 0)
		WT += t;
}

void Patient::UpdateTT(int t) {
	if (t > 0)
		TT += t;
}

void Patient::SetFT(int t) {
	if (t > 0)
		FT = t;
}


int Patient::GetFT() const {
	return FT;
}

int Patient::GetID() {
	return ID;
}

int Patient::GetPT() const {
	return PT;
}

int Patient::GetVT() const {
	return VT;
}

int Patient::GetTT() const {
	return TT;
}
int Patient::GetWT() const {
	return WT;
}

char Patient::GetType() const {
	return Type;
}

string Patient::GetStatus() const {
	return Status;
}

bool Patient::operator<=(Patient*& p) {
	return (this->PT <= p->PT);
}

bool Patient::operator>=(Patient*& p) {
	return (this->PT >= p->PT);
}