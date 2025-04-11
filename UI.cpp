#include "UI.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

UI::UI()
{
    
}
void UI::OutputScreen(){
    cout << "Current Timestep: " << s.GetTimestep()<< "\n";
    cin.get();//buffer  wating till press enter key 
    cout << "=============== ALL List ===============\n";
    cout << s.GetTP() << " patients remaining: ";
    s.Get_All_Patients().PrintQueue(s.Get_All_Patients(),10);


    cout << "===============  Waiting Lists ===============\n";
    cout << s.Get_E_Waiting().GetCount() << " E-therapy patients: ";
    s.Get_E_Waiting().PrintQueue(s.Get_E_Waiting());

    cout << s.Get_U_Waiting().GetCount() << " U-therapy patients: ";
    s.Get_U_Waiting().PrintQueue(s.Get_U_Waiting());

    cout << s.Get_X_Waiting().GetCount() << " X-therapy patients: ";
    s.Get_X_Waiting().PrintQueue(s.Get_X_Waiting());


    cout << "===============  Early List ===============\n";
    cout << s.Get_Early_List().GetCount() << " patients: ";      
    s.Get_Early_List().PrintQueue(s.Get_Early_List());

    cout << "===============  Late List ===============\n";
    cout << s.Get_Late_List().GetCount() << " patients: ";     
    s.Get_Late_List().PrintQueue(s.Get_Late_List());


    cout << "===============  Avail E-devices ===============\n";
    cout << s.Get_AvailE_Devices().GetCount() << " Electro device: ";
    s.Get_AvailE_Devices().PrintQueue(s.Get_AvailE_Devices());

    cout << "===============  Avail U-devices ===============\n";
    cout << s.Get_AvailU_Devices().GetCount() << " Ultra device: ";
    s.Get_AvailU_Devices().PrintQueue(s.Get_AvailU_Devices());

    cout << "===============  Avail X-devices ===============\n";
    cout << s.Get_AvailX_Rooms().GetCount() << " rooms: ";
    s.Get_AvailX_Rooms().PrintQueue(s.Get_AvailX_Rooms());


    cout << "===============  In-treatment List ===============\n";
    cout << s.Get_In_Treatment().GetCount() << " ==> ";                 
    s.Get_In_Treatment().PrintQueue(s.Get_In_Treatment());

    cout << " ----------------------------------------\n";
    cout << s.Get_Finish_List().GetCount() << " ==> ";                 
    s.Get_Finish_List().PrintStack(s.Get_Finish_List());

}

