#include "LinkedQueue.h"
#include "priQueue.h"
#include "SortedQueue.h"
#include "UI.h"
#include "Scheduler.h"

using namespace std;

int main() {
	//Scheduler s // ui u;

	cout << "Choose The Mode.." << endl;
	cout << "1- Interactive Mode\n2- Silent Mode" << endl;
	int mode;
	cin >> mode;
	while (mode != 1 && mode != 2) {
		cout << "Invalid mode. Please try again (enter 1 or 2): "<<endl;
		cin >> mode;
	}	

	if(mode == 1){
		//
		//
		cout << "1";
	}
	else {
		//
		cout << "2till now we are in phase 1\nwill work soon in phase 2";
		// will call a function in sheduler that create a output file
	}
	return 0;
}
