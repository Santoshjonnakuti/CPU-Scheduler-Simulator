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
        if (p1.getBurstTime() == p2.getBurstTime())
        {
            if (p1.getArrivalTime() == p2.getArrivalTime())
            {
                return p1.getProcessId() > p2.getProcessId();
            }
            return p1.getArrivalTime() > p2.getArrivalTime();
        }
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
        Process P = readyQueue.top();
        writeDataToStatusFile(P.Data, status, t);
        return;
    }
    void writeProcessesFile(ProcessDetails_t Data)
    {
        writeDataToProcessesFile(Data);
    }
    void SRTF(Process_Creator &PC, int t)
    {
        checkProcessesArrival(PC, t);
        if (readyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            if (P.Data.burstTime != 0)
            {
                writeStatusFile("Running", t);
                P.Data.burstTime -= 1;
                if (P.Data.responseTime == -1)
                {
                    P.Data.responseTime = t - P.Data.arrivalTime;
                }
                readyQueue.pop();
                readyQueue.push(Process(P.Data));
            }
            else
            {
                writeStatusFile("Exit", t);
                P.Data.completionTime = t;
                P.Data.turnAroundTime = P.Data.completionTime - P.Data.arrivalTime;
                P.Data.waitingTime = P.Data.turnAroundTime - P.Data.burstTime1;
                writeProcessesFile(P.Data);
                readyQueue.pop();
                if (readyQueue.empty() == false)
                {
                    P = readyQueue.top();
                    writeStatusFile("Running", t);
                    P.Data.burstTime -= 1;
                    if (P.Data.responseTime == -1)
                    {
                        P.Data.responseTime = t - P.Data.arrivalTime;
                    }
                    readyQueue.pop();
                    readyQueue.push(Process(P.Data));
                }
                printWarningMessage("\nProcess Completed...\n");
            }
            // P.printProcessDetails();
            P.printPidATBT();
        }
    }
    friend class Scheduler;
};
#endif