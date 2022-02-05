#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>

using namespace std;

// Process Class members Data type
struct ProcessDetails_t
{
    int processId;
    int arrivalTime;
    int burstTime;
    int burstTime1;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};
#endif