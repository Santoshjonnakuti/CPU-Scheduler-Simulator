#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <bits/stdc++.h>
#include "Process.h"
#include "ProcessCreator.h"

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
    Scheduler(Process_Creator &PC)
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