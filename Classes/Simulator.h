#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "ProcessCreator.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "SRTF.h"
#include "RR.h"

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
        if (schedulingAlgorithm.compare("FCFS") == 0)
        {
            FCFSScheduler Fcfs(PC);
            for (int i = 0; i < simulationTime; i++)
            {
                cout << "\nIteration is " << i << endl;
                Fcfs.FCFS(PC, i);
            }
            return;
        }
        else if (schedulingAlgorithm.compare("SRTF") == 0)
        {
            SRTFScheduler Srtf(PC);
            for (int i = 0; i < simulationTime; i++)
            {
                cout << "\nIteration is " << i << endl;
                Srtf.SRTF(PC, i);
            }
            return;
        }
        else
        {
            RRScheduler Rr(PC);
            Rr.RR();
            return;
        }
    }
};

#endif