#ifndef PROCESSCREATOR_H
#define PROCESSCREATOR_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Utils/DataTypes.h"
#include "Process.h"

using namespace std;

class Process_Creator
{
    // Array of Processes
    Process **Processes;
    int noOfProcesses;

public:
    Process_Creator(int noOfProcesses)
    {
        this->noOfProcesses = noOfProcesses;
        ProcessDetails_t PD;
        PD.completionTime = -1;
        PD.turnAroundTime = -1;
        PD.waitingTime = -1;
        PD.responseTime = -1;
        // Allocates Memory for the Array
        Processes = (Process **)malloc(noOfProcesses * sizeof(Process *));
        // Initializing the arrival time and burst time with some random values inbetween 1 and 1000
        srand(time(0));
        int prevAT = 0, preAT, preBT;
        for (int i = 0; i < noOfProcesses; i++)
        {
            preAT = rand();
            preBT = rand();
            PD.processId = i + 1;
            PD.arrivalTime = 1 + prevAT + preAT % 1000;
            PD.burstTime = 1 + preBT % 1000;
            PD.burstTime1 = PD.burstTime;
            Processes[i] = new Process(PD);
            prevAT = PD.arrivalTime;
        }
        for (int i = 0; i < noOfProcesses; i++)
        {
            Processes[i]->printProcessDetails();
        }
    }
    // to print all Processes Details
    void printAllProcessDetails()
    {
        for (int i = 0; i < noOfProcesses; i++)
        {
            Processes[i]->printProcessDetails();
        }
    }
    // Scheduler as Friend class for Process_Creator
    // Scheduler can access the private members of this class
    friend class Scheduler;
    friend class FCFSScheduler;
    friend class SRTFScheduler;
    friend class RRScheduler;
};

#endif