#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <bits/stdc++.h>
#include "Process.h"
#include "ProcessCreator.h"
#include "FCFS.h"
#include "SRTF.h"
#include "RR.h"
#include "../Utils/FileHandling.h"

using namespace std;
class Comparator
{
public:
    int operator()(const Process &p1, const Process &p2)
    {
        return p1.getBurstTime() > p2.getBurstTime();
    }
};
class Scheduler
{
    // Min Heap
    // ready Queue
    priority_queue<Process, vector<Process>, Comparator> readyQueue;

public:
    void ScheduleProcesses(Process_Creator &PC, int simulationTime, int timeQuantum, string schedulingAlgorithm)
    {
        if (schedulingAlgorithm.compare("FCFS") == 0)
        {
            FCFSScheduler Fcfs(PC);
            for (int i = 1; i <= simulationTime; i++)
            {
                cout << "\nIteration is " << i << endl;
                Fcfs.FCFS(PC, i);
            }
            while (Fcfs.readyQueue.empty() == false)
            {
                Process P = Fcfs.readyQueue.top();
                writeDataToProcessesFile(P.Data);
                Fcfs.readyQueue.pop();
            }
            return;
        }
        else if (schedulingAlgorithm.compare("SRTF") == 0)
        {
            SRTFScheduler Srtf(PC);
            for (int i = 1; i <= simulationTime; i++)
            {
                cout << "\nIteration is " << i << endl;
                Srtf.SRTF(PC, i);
            }
            while (Srtf.readyQueue.empty() == false)
            {
                Process P = Srtf.readyQueue.top();
                writeDataToProcessesFile(P.Data);
                Srtf.readyQueue.pop();
            }
            return;
        }
        else
        {
            RRScheduler Rr(PC, timeQuantum);
            for (int i = 1; i <= simulationTime; i++)
            {
                cout << "\nIteration is " << i << endl;
                Rr.RR(PC, i);
            }
            while (Rr.readyQueue.empty() == false)
            {
                Process P = Rr.readyQueue.top();
                writeDataToProcessesFile(P.Data);
                Rr.readyQueue.pop();
            }
            return;
        }
    }
};
#endif