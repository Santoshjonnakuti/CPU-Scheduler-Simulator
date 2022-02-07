#ifndef RR_H
#define RR_H

#include <iostream>
#include <bits/stdc++.h>
#include "Process.h"
#include "ProcessCreator.h"
#include "../Utils/FileHandling.h"

using namespace std;
class RRComparator
{
public:
    int operator()(const Process &p1, const Process &p2)
    {
        if (p1.getArrivalTime() == p2.getArrivalTime())
        {
            return p1.getProcessId() > p2.getProcessId();
        }
        return p1.getArrivalTime() > p2.getArrivalTime();
    }
};
class RRScheduler
{
    // Min Heap ready Queue
    priority_queue<Process, vector<Process>, RRComparator> readyQueue;
    priority_queue<Process, vector<Process>, RRComparator> readyQueue1;
    int counter, timeQuantum;

public:
    RRScheduler(Process_Creator &PC, int tQ)
    {
        counter = 0;
        timeQuantum = tQ;
        // Constructor of The Class
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
    void RR(Process_Creator PC, int t)
    {
        checkProcessesArrival(PC, t);
        if (readyQueue.empty() == true && readyQueue1.empty() == false)
        {
            while (readyQueue1.empty() == false)
            {
                Process P = readyQueue1.top();
                readyQueue1.pop();
                readyQueue.push(Process(P.Data));
            }
        }
        if (readyQueue.empty() == false)
        {
            if (counter == timeQuantum)
            {
                counter = 0;
                Process P = readyQueue.top();
                readyQueue.pop();
                readyQueue1.push(Process(P.Data));
                if (readyQueue.empty() == true && readyQueue1.empty() == false)
                {
                    while (readyQueue1.empty() == false)
                    {
                        Process P = readyQueue1.top();
                        readyQueue1.pop();
                        readyQueue.push(Process(P.Data));
                    }
                }
            }
            counter += 1;
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