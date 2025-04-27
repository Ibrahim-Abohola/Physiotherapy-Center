#include "UI2.h"
#include <iostream>
#include <iomanip>

using namespace std;

UI::UI(Scheduler * sched) {
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

string UI::GetOutputFile()
{
    cout << "Enter the name of the output file" << endl;
    string out;
    cin >> out;
    out += ".txt";
    return out;
}
void UI::OutToFile()
{
    string out = GetOutputFile();
    ofstream Output;
    Output.open(out);
    Output << left  // align text to the left
        << setw(5) << "PID"
        << setw(8) << "PType"
        << setw(5) << "PT"
        << setw(5) << "VT"
        << setw(5) << "FT"
        << setw(5) << "WT"
        << setw(5) << "TT"
        << setw(8) << "Cancel"
        << setw(5) << "Resc" << '\n';
    int co = scheduler->Get_Finish_List().GetCount();
    for (int i = 0; i < co; i++) {
        Patient* patient = NULL;
        scheduler->Get_Finish_List().pop(patient);

        Output << left
            << setw(7) << ("P" + to_string(patient->GetID()))
            << setw(6) << patient->GetType()
            << setw(5) << patient->GetPT()
            << setw(5) << patient->GetVT()
            << setw(5) << patient->GetFT()
            << setw(5) << patient->GetWT()
            << setw(7) << patient->GetTT()
            << setw(8) << (patient->GetisCanceled() ? "T" : "F")
            << (patient->GetisRscheduled() ? "T\n" : "F\n");
    }

    Output << "\nTotal number of timesteps = " << scheduler->GetTimestep() << "\n";

    Output << "Total number of all, N, and R patients = "
        << scheduler->GetTP() << ", "
        << scheduler->GetTotal_NPatients() << ", "
        << scheduler->GetTotal_RPatients() << "\n";

    Output << "Average total waiting time for all, N, and R patients = "
        << scheduler->GetAvgTWT() << ", "
        << scheduler->GetAvgWT_N() << ", "
        << scheduler->GetAvgWT_R() << "\n";

    Output << "Average total treatment time for all, N, and R patients = "
        << scheduler->GetAvgTTT() << ", "
        << scheduler->GetAvgTT_N() << ", "
        << scheduler->GetAvgTT_R() << "\n";

    Output << "Percentage of patients of an accepted cancellation (%) = " << scheduler->GetPer_cancellation() << " %\n";
    Output << "Percentage of patients of an accepted rescheduling (%) = " << scheduler->GetPer_rescheduling() << " %\n";
    Output << "Percentage of early patients (%) = " << scheduler->GetPer_Early() << " %\n";
    Output << "Percentage of late patients (%) = " << scheduler->GetPer_Late() << " %\n";
    Output << "Average late penalty = " << scheduler->GetAvgPenality() << " timestep(s)\n";

    Output.close();

}