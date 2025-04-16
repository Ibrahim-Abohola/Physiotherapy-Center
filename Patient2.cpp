#include "Patient2.h"

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

void Patient::AddTreatment(Treatment* treatment)
{
	TreatmentList.enqueue(treatment);
}

void Patient::RemoveTreatment(Resource *& r)
{
	Treatment * treatment;
	TreatmentList.dequeue(treatment);
	r = treatment->GetResource();
	delete treatment;
	treatment = NULL;
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
void Patient::SetPT(int t) {
	PT = t;
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

void Patient::ModifyPT(int t)
{
	if (t > PT)
		PT = t;
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
int Patient::GetPenality()  const {
	return Penality;
}

char Patient::GetType() const {
	return Type;
}

string Patient::GetStatus() const {
	return Status;
}

Treatment* Patient::GetCurrentTreatment() {
	Treatment * curr;
	TreatmentList.peek(curr);
	if (curr)
		return curr;
	return NULL;
}

bool Patient::operator<=(Patient*& p) {
	return (PT + Penality <= p->PT + p->Penality);
}

bool Patient::operator>=(Patient*& p) {
	return (PT + Penality >= p->PT + p->Penality);
}


int Patient::operator!() {

	Treatment* t;
	TreatmentList.peek(t);
	return (t->getDuration());
}

bool Patient::operator~() 
{
	return (TreatmentList.GetCount() == 1);
}
ostream& operator<<(ostream& os, const Patient& p) {
	os << "P" << p.GetID() << "_" << p.GetVT();
	return os;
}
