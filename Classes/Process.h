#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
#include "../Utils/DataTypes.h"
#include "../Utils/Messages.h"

using namespace std;

class Process
{
    // data members
    ProcessDetails_t Data;
    // default Constructor
public:
    Process()
    {
        cout << "\nDefault Constructor Called\n"
             << endl;
    }
    // parameterized Constructor
    Process(int processId, int arivalTime, int burstTime, int completionTime, int turnAroundTime, int waitingTime, int responseTime)
    {
        this->Data.processId = processId;
        this->Data.arrivalTime = arivalTime;
        this->Data.burstTime = burstTime;
        this->Data.completionTime = completionTime;
        this->Data.turnAroundTime = turnAroundTime;
        this->Data.waitingTime = waitingTime;
        this->Data.responseTime = responseTime;
    }
    // function to assign Data Members
    void assignProcessDetails(int processId, int arivalTime, int burstTime, int completionTime, int turnAroundTime, int waitingTime, int responseTime)
    {
        this->Data.processId = processId;
        this->Data.arrivalTime = arivalTime;
        this->Data.burstTime = burstTime;
        this->Data.completionTime = completionTime;
        this->Data.turnAroundTime = turnAroundTime;
        this->Data.waitingTime = waitingTime;
        this->Data.responseTime = responseTime;
    }
    // function to display Process Properties
    void printProcessDetails()
    {
        printProcessInformation(Data);
    }
};
#endif