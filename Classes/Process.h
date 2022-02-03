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
    Process(ProcessDetails_t PD)
    {
        this->Data.processId = PD.processId;
        this->Data.arrivalTime = PD.arrivalTime;
        this->Data.burstTime = PD.burstTime;
        this->Data.completionTime = PD.completionTime;
        this->Data.turnAroundTime = PD.turnAroundTime;
        this->Data.waitingTime = PD.waitingTime;
        this->Data.responseTime = PD.responseTime;
    }
    // function to assign Data Members
    void assignProcessDetails(ProcessDetails_t PD)
    {
        this->Data.processId = PD.processId;
        this->Data.arrivalTime = PD.arrivalTime;
        this->Data.burstTime = PD.burstTime;
        this->Data.completionTime = PD.completionTime;
        this->Data.turnAroundTime = PD.turnAroundTime;
        this->Data.waitingTime = PD.waitingTime;
        this->Data.responseTime = PD.responseTime;
    }
    // function to display Process Properties
    void printProcessDetails()
    {
        printProcessInformation(Data);
    }
    void printPidATBT()
    {
        printProcessIdATBT(Data);
    }
    int getArrivalTime() const { return Data.arrivalTime; }
    int getBurstTime() const { return Data.burstTime; }
    friend class Scheduler;
    friend class FCFSScheduler;
    friend class SRTFScheduler;
    friend class RRScheduler;
};
#endif