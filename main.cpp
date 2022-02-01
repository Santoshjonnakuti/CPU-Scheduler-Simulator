#include <iostream>
#include <string>

#include "../Classes/Process.h"

using namespace std;

int main()
{
    int simulationTime;
    int timeQuantum;
    string schedulingAlgorithm;
    cout << "Enter Simulation Time [in ms]: ";
    cin >> simulationTime;
    cout << "Enter Scheduling Algorithm [FCFS/SRTF/RR]: ";
    cin >> schedulingAlgorithm;
    if (!schedulingAlgorithm.compare("RR"))
    {
        cout << "Enter Time Quantum [in ms]: ";
        cin >> timeQuantum;
    }
    Process P();

    return 0;
}