#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>

using namespace std;

struct ProcessDetails_t
{
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};
#endif