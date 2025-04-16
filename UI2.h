#pragma once

#include <iostream>
#include "Scheduler.h"
#include "priQueue.h"


using namespace std;

class UI {
    Scheduler* scheduler;
public:
    UI(Scheduler* sched);
    void OutputScreen();
    string GetInputFile();


};
