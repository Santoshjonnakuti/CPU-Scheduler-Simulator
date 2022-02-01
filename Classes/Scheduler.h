#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "Process.h"
#include "ProcessCreator.h"

using namespace std;

class Scheduler
{
    Process **readyQueue;

public:
    Scheduler(Process_Creator &PC)
    {
        readyQueue = (Process **)malloc(PC.noOfProcesses * sizeof(Process *));
    }
    void FCFS()
    {
        // First Come First Serve Algorithm
    }
    void SRTF()
    {
        // Shortest Remaining Time First Algorithm
    }
    void RR()
    {
        // Round Robin Algorithm
    }
};

#endif