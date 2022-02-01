#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>

using namespace std;

class Process
{
    // data members
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
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
        this->processId = processId;
        this->arrivalTime = arivalTime;
        this->burstTime = burstTime;
        this->completionTime = completionTime;
        this->turnAroundTime = turnAroundTime;
        this->waitingTime = waitingTime;
        this->responseTime = responseTime;
    }
    // function to assign Data Members
    void assignProcessDetails(int processId, int arivalTime, int burstTime, int completionTime, int turnAroundTime, int waitingTime, int responseTime)
    {
        this->processId = processId;
        this->arrivalTime = arivalTime;
        this->burstTime = burstTime;
        this->completionTime = completionTime;
        this->turnAroundTime = turnAroundTime;
        this->waitingTime = waitingTime;
        this->responseTime = responseTime;
    }
    // function to display Process Properties
    void printProcessDetails()
    {
        cout << "------------------------------Process Details------------------------------" +
                    string("\nProcess ID                 : ") + to_string(processId) +
                    "\nProcess Arrival Time       : " + to_string(arrivalTime) +
                    "\nProcess Burst Time         : " + to_string(burstTime) +
                    "\nProcess Completion Time    : " + to_string(completionTime) +
                    "\nProcess Turn Around Time   : " + to_string(turnAroundTime) +
                    "\nProcess Waiting Time       : " + to_string(waitingTime) +
                    "\nProcess Response Time      : " + to_string(responseTime);
    }
};
#endif