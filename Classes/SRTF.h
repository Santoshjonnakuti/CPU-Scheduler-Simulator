#ifndef SRTF_H
#define SRTF_H

#include <iostream>
#include <bits/stdc++.h>
#include "Process.h"
#include "ProcessCreator.h"
#include "../Utils/FileHandling.h"

using namespace std;
class SRTFComparator
{
public:
    int operator()(const Process &p1, const Process &p2)
    {
        return p1.getBurstTime() > p2.getBurstTime();
    }
};
class SRTFScheduler
{
    // Min Heap ready Queue
    priority_queue<Process, vector<Process>, SRTFComparator> readyQueue;

public:
    SRTFScheduler(Process_Creator &PC)
    {
        // Constructor of the Class
    }
    void checkProcessesArrival(Process_Creator &PC, int t)
    {
        for (int i = 0; i < PC.noOfProcesses; i++)
        {
            if (PC.Processes[i]->Data.arrivalTime == t)
            {
                readyQueue.push(Process(PC.Processes[i]->Data));
                cout << "t and AT Matched" << PC.Processes[i]->Data.arrivalTime << endl;
            }
        }
    }
    void writeStatusFile(const char status[], int t)
    {
        Process P = readyQueue.top();
        writeDataToStatusFile(P.Data, status, t);
        return;
    }
    void SRTF(Process_Creator &PC, int t)
    {
        char const *A = "Arrived";
        char const *R = "Running";
        char const *E = "Exit";
        checkProcessesArrival(PC, t);
        if (readyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            if (P.Data.arrivalTime != t)
            {
                P.Data.burstTime -= 1;
                if (P.Data.burstTime != 0)
                {
                    writeStatusFile(R, t);
                    readyQueue.pop();
                    readyQueue.push(Process(P.Data));
                }
                else
                {
                    writeStatusFile(E, t);
                    readyQueue.pop();
                    printWarningMessage("\nProcess Completed...\n");
                }
                // P.printProcessDetails();
                P.printPidATBT();
            }
            else
            {
                writeStatusFile(A, t);
            }
        }
    }
};
#endif