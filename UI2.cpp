#include "UI.h"
#include <iostream>

using namespace std;

UI::UI(Scheduler* sched) {
    scheduler = sched;
}
void UI::OutputScreen() {

    cout << "Current Timestep: " << scheduler->GetTimestep() << "\n";
    cout << "=============== ALL List ===============\n";
    cout << scheduler->Get_All_Patients().GetCount() << " Patients remaining: ";
    scheduler->Get_All_Patients().PrintQueue(10);
    cout << endl;


    cout << "\n===============  Waiting Lists ===============\n";
    cout << scheduler->Get_E_Waiting().GetCount() << " E-therapy Patients: ";
    scheduler->Get_E_Waiting().PrintQueue();
    cout << endl;
    cout << scheduler->Get_U_Waiting().GetCount() << " U-therapy Patients: ";
    scheduler->Get_U_Waiting().PrintQueue();
    cout << endl;
    cout << scheduler->Get_X_Waiting().GetCount() << " X-therapy Patients: ";
    scheduler->Get_X_Waiting().PrintQueue();
    cout << endl;


    cout << "===============  Early List ===============\n";
    cout << scheduler->Get_Early_List().GetCount() << " Patients: ";
    scheduler->Get_Early_List().PrintQueue();
    cout << endl;

    cout << "===============  Late List ===============\n";
    cout << scheduler->Get_Late_List().GetCount() << " Patients: ";
    scheduler->Get_Late_List().PrintQueue();
    cout << endl;


    cout << "===============  Avail E-devices ===============\n";
    cout << scheduler->Get_AvailE_Devices().GetCount() << " Electro devices: ";
    scheduler->Get_AvailE_Devices().PrintQueue();
    cout << endl;

    cout << "===============  Avail U-devices ===============\n";
    cout << scheduler->Get_AvailU_Devices().GetCount() << " Ultra devices: ";
    scheduler->Get_AvailU_Devices().PrintQueue();
    cout << endl;

    cout << "===============  Avail X-Room ===============\n";
    cout << scheduler->Get_AvailX_Rooms().GetCount() << " Rooms: ";
    scheduler->Get_AvailX_Rooms().PrintQueue();
    cout << endl;

    cout << "===============  In-treatment List ===============\n";
    cout << scheduler->Get_In_Treatment().GetCount() << " ==> ";
    scheduler->Get_In_Treatment().PrintQueue();
    cout << endl;

    cout << "---------------------------------------------------\n";
    cout << scheduler->Get_Finish_List().GetCount() << " ==> finished patients ";
    scheduler->Get_Finish_List().PrintStack();
    cout << endl;
    cout << "Press any key to display the next time step" << endl;
    cout << endl;
    cout << "=========================================================" << endl;
}

string UI::GetInputFile()
{
    cout << "Enter the name of the input file" << endl;
    string in;
    cin >> in;
    in += ".txt";
    return in;
}