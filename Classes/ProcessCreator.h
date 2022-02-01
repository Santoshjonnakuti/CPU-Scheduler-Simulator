#ifndef PROCESSCREATOR_H
#define PROCESSCREATOR_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Utils/DataTypes.h"
#include "Process.h"
#include "Scheduler.h"

using namespace std;

class Process_Creator
{
    // Array of Processes
    Process **A;
    int noOfProcesses;

public:
    Process_Creator(int noOfProcesses)
    {
        this->noOfProcesses = noOfProcesses;
        ProcessDetails_t PD;
        PD.completionTime = 0;
        PD.turnAroundTime = 0;
        PD.waitingTime = 0;
        PD.responseTime = 0;
        // Allocates Memory for the Array
        A = (Process **)malloc(noOfProcesses * sizeof(Process *));
        // Initializing the arrival time and burst time with some random values inbetween 1 and 1000
        srand(time(0));
        for (int i = 0; i < noOfProcesses; i++)
        {
            PD.processId = i + 1;
            PD.arrivalTime = 1 + rand() % 1000;
            PD.burstTime = 1 + rand() % 1000;
            A[i] = new Process(PD);
        }
        for (int i = 0; i < noOfProcesses; i++)
        {
            A[i]->printProcessDetails();
        }
    }
    // to print all Processes Details
    void printAllProcessDetails()
    {
        for (int i = 0; i < noOfProcesses; i++)
        {
            A[i]->printProcessDetails();
        }
    }
    // Scheduler as Friend class for Process_Creator
    // Scheduler can access the private members of this class
    friend class Scheduler;
};

#endif