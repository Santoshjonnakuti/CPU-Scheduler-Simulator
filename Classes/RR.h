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
        priority_queue<Process, vector<Process>, SRTFComparator> dupReadyQueue;
        priority_queue<Process, vector<Process>, SRTFComparator> dupReadyQueue1;
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
                continue;
            }
            writeDataToStatusFile(P.Data, "Waiting", t);
        }
        while (dupReadyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            readyQueue.push(Process(P.Data));
            dupReadyQueue.pop();
        }
        while (readyQueue1.empty() == false)
        {
            Process P = readyQueue1.top();
            dupReadyQueue1.push(Process(P.Data));
            readyQueue1.pop();
            writeDataToStatusFile(P.Data, "Waiting", t);
        }
        while (dupReadyQueue1.empty() == false)
        {
            Process P = readyQueue1.top();
            readyQueue1.push(Process(P.Data));
            dupReadyQueue1.pop();
        }
        return;
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
                readyQueue.pop();
                readyQueue.push(Process(P.Data));
            }
            else
            {
                writeStatusFile("Exit", t);
                readyQueue.pop();
                if (readyQueue.empty() == false)
                {
                    P = readyQueue.top();
                    P.Data.burstTime -= 1;
                    readyQueue.pop();
                    readyQueue.push(Process(P.Data));
                }
                printWarningMessage("\nProcess Completed...\n");
            }
            // P.printProcessDetails();
            P.printPidATBT();
        }
    }
};
#endif