#include <iostream>
#include <string>
#include "./Classes/Process.h"
#include "./Classes/ProcessCreator.h"
#include "./Classes/Scheduler.h"
#include "./Utils/Messages.h"
#include "./Utils/FileHandling.h"
#include "./Classes/Simulator.h"

using namespace std;

int main()
{
    int simulationTime;
    int timeQuantum;
    int numberOfProcesses;
    string schedulingAlgorithm;
    takeInput("Enter Simulation Time [in ms]: ");
    cin >> simulationTime;
    takeInput("Enter Scheduling Algorithm [FCFS/SRTF/RR]: ");
    cin >> schedulingAlgorithm;
    if (!schedulingAlgorithm.compare("RR"))
    {
        takeInput("Enter Time Quantum [in ms]: ");
        cin >> timeQuantum;
    }
    takeInput("Enter Number Of Process : ");
    cin >> numberOfProcesses;
    writeHeadersToStatusFile();
    writeHeadersToProcessesFile();
    Simulator Simulation(simulationTime, timeQuantum, numberOfProcesses, schedulingAlgorithm);
    Simulation.start();
    return 0;
}