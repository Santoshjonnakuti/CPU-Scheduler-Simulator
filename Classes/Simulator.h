#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>

using namespace std;

class Simulator
{
private:
    int simulationTime;
    int timeQuantum;
    string schedulingAlgorithm;
    Simulator(int sT, int tQ, string sA)
    {
        simulationTime = sT;
        timeQuantum = tQ;
        schedulingAlgorithm = sA;
    }
    void start()
    {
    }
};

#endif