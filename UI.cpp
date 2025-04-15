#include "UI.h"
#include <iostream>

using namespace std;

UI::UI(Scheduler sched){
    scheduler = new Scheduler(sched);
}
void UI::OutputScreen(){
    cout << "Current Timestep: " << scheduler->GetTimestep()<< "\n";
    cin.get();//buffer  wating till press enter key 
    cout << "=============== ALL List ===============\n";
    cout << scheduler->GetTP() << " patients remaining: ";
    scheduler->Get_All_Patients().PrintQueue(scheduler->Get_All_Patients(),10);


    cout << "\n===============  Waiting Lists ===============\n";
    cout << scheduler->Get_E_Waiting().GetCount() << " E-therapy patients: ";
    scheduler->Get_E_Waiting().PrintQueue(scheduler->Get_E_Waiting());

    cout << scheduler->Get_U_Waiting().GetCount() << " U-therapy patients: ";
    scheduler->Get_U_Waiting().PrintQueue(scheduler->Get_U_Waiting());

    cout << scheduler->Get_X_Waiting().GetCount() << " X-therapy patients: ";
    scheduler->Get_X_Waiting().PrintQueue(scheduler->Get_X_Waiting());


    cout << "===============  Early List ===============\n";
    cout << scheduler->Get_Early_List().GetCount() << " patients: ";
    scheduler->Get_Early_List().PrintQueue(scheduler->Get_Early_List());

    cout << "===============  Late List ===============\n";
    cout << scheduler->Get_Late_List().GetCount() << " patients: ";
    scheduler->Get_Late_List().PrintQueue(scheduler->Get_Late_List());


    cout << "===============  Avail E-devices ===============\n";
    cout << scheduler->Get_AvailE_Devices().GetCount() << " Electro device: ";
    scheduler->Get_AvailE_Devices().PrintQueue(scheduler->Get_AvailE_Devices());

    cout << "===============  Avail U-devices ===============\n";
    cout << scheduler->Get_AvailU_Devices().GetCount() << " Ultra device: ";
    scheduler->Get_AvailU_Devices().PrintQueue(scheduler->Get_AvailU_Devices());

    cout << "===============  Avail X-devices ===============\n";
    cout << scheduler->Get_AvailX_Rooms().GetCount() << " rooms: ";
    scheduler->Get_AvailX_Rooms().PrintQueue(scheduler->Get_AvailX_Rooms());


    cout << "===============  In-treatment List ===============\n";
    cout << scheduler->Get_In_Treatment().GetCount() << " ==> ";
    scheduler->Get_In_Treatment().PrintQueue(scheduler->Get_In_Treatment());

    cout << " ----------------------------------------\n";
    cout << scheduler->Get_Finish_List().GetCount() << " ==> ";
    scheduler->Get_Finish_List().PrintStack(scheduler->Get_Finish_List());

}

