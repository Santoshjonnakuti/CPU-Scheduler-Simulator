#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "ProcessCreator.h"
#include "FCFS.h"
#include "SRTF.h"
#include "RR.h"
#include "../Utils/FileHandling.h"

using namespace std;

class Simulator
{
private:
    int simulationTime;
    int timeQuantum;
    int noOfProcesses;
    string schedulingAlgorithm;

public:
    Simulator(int sT, int tQ, int nP, string sA)
    {
        simulationTime = sT;
        timeQuantum = tQ;
        noOfProcesses = nP;
        schedulingAlgorithm = sA;
    }
    void start()
    {
        Process_Creator PC(noOfProcesses);
        Scheduler S;
        S.ScheduleProcesses(PC, simulationTime, timeQuantum, schedulingAlgorithm);
    }
    friend class Scheduler;
};

#endif