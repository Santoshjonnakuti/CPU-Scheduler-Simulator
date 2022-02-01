#ifndef MESSAGES_H
#define MESSAGES_H

#include <iostream>
#include <string>
#include "DataTypes.h"

using namespace std;

void printErrorMessage(string errorMessage)
{
    string error = "\033[1;31m" + errorMessage + "\033[0m\n";
    cout << error << endl;
}
void printSuccessMessage(string successMessage)
{
    string success = "\033[1;32m" + successMessage + "\033[0m\n";
    cout << success << endl;
}
void printWarningMessage(string warningMessage)
{
    string warning = "\033[1;33m" + warningMessage + "\033[0m\n";
    cout << warning << endl;
}
void printInformation(string informationMessage)
{
    string information = "\033[1;34m" + informationMessage + "\033[0m\n";
    cout << information << endl;
}
void takeInput(string message)
{
    string msg = "\033[1;33m" + message + "\033[0m";
    cout << msg;
}
void printProcessInformation(ProcessDetails_t Data)
{
    printInformation("\n------------------------------Process Details------------------------------\n" +
                     string("\nProcess ID                 : ") + to_string(Data.processId) +
                     "\nProcess Arrival Time       : " + to_string(Data.arrivalTime) +
                     "\nProcess Burst Time         : " + to_string(Data.burstTime) +
                     "\nProcess Completion Time    : " + to_string(Data.completionTime) +
                     "\nProcess Turn Around Time   : " + to_string(Data.turnAroundTime) +
                     "\nProcess Waiting Time       : " + to_string(Data.waitingTime) +
                     "\nProcess Response Time      : " + to_string(Data.responseTime) + "\n");
}
#endif