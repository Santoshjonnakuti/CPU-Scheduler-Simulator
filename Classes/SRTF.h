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
                writeDataToStatusFile(PC.Processes[i]->Data, "Arrived", t);
                cout << "t and AT Matched" << PC.Processes[i]->Data.arrivalTime << endl;
            }
        }
    }
    void writeStatusFile(const char status[], int t)
    {
        priority_queue<Process, vector<Process>, SRTFComparator> dupReadyQueue;
        Process P = readyQueue.top();
        dupReadyQueue.push(Process(P.Data));
        readyQueue.pop();
        writeDataToStatusFile(P.Data, status, t);
        int k = 0;
        while (readyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            dupReadyQueue.push(Process(P.Data));
            readyQueue.pop();
            if (k == 0 && strcmp(status, "Exit") == 0)
            {
                writeDataToStatusFile(P.Data, "Running", t);
                k = 1;
            }
            writeDataToStatusFile(P.Data, "Waiting", t);
        }
        while (dupReadyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            readyQueue.push(Process(P.Data));
            dupReadyQueue.pop();
        }
        return;
    }
    void SRTF(Process_Creator &PC, int t)
    {
        checkProcessesArrival(PC, t);
        if (readyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            if (P.Data.burstTime != -1)
            {
                writeStatusFile("Running", t);
                P.Data.burstTime -= 1;
                readyQueue.pop();
                readyQueue.push(Process(P.Data));
            }
            else
            {
                writeStatusFile("Exit", t);
                readyQueue.pop();
                printWarningMessage("\nProcess Completed...\n");
            }
            // P.printProcessDetails();
            P.printPidATBT();
        }
    }
};
#endif