#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include <bits/stdc++.h>
#include "Process.h"
#include "ProcessCreator.h"

using namespace std;
class FCFSComparator
{
public:
    int operator()(const Process &p1, const Process &p2)
    {
        return p1.getArrivalTime() > p2.getArrivalTime();
    }
};
class FCFSScheduler
{
    // Min Heap ready Queue
    priority_queue<Process, vector<Process>, FCFSComparator> readyQueue;

public:
    FCFSScheduler(Process_Creator &PC)
    {
        for (int i = 0; i < PC.noOfProcesses; i++)
        {
            readyQueue.push(Process(PC.Processes[i]->Data));
        }
    }
    void FCFS()
    {
        while (readyQueue.empty() == false)
        {
            Process P = readyQueue.top();
            P.printProcessDetails();
            readyQueue.pop();
        }
    }
};
#endif