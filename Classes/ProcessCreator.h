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
        A = (Process **)malloc(noOfProcesses * sizeof(Process *));
        srand(time(0));
        for (int i = 0; i < noOfProcesses; i++)
        {
            PD.processId = i + 1;
            PD.arrivalTime = 1 + rand() % 9;
            PD.burstTime = 1 + rand() % 9;
            A[i] = new Process(PD);
        }
        for (int i = 0; i < noOfProcesses; i++)
        {
            A[i]->printProcessDetails();
        }
    }
    void printAllProcessDetails()
    {
        for (int i = 0; i < noOfProcesses; i++)
        {
            A[i]->printProcessDetails();
        }
    }
};

#endif