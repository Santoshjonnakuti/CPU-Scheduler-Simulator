#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"
#include "Messages.h"

void writeHeadersToStatusFile()
{
    FILE *filePointer;
    filePointer = fopen("./Files/status.txt", "w");
    if (filePointer == NULL)
    {
        printErrorMessage("\nUnable To Update Status File...\n");
    }
    fprintf(filePointer, "Milli Seconds\t\tProcess Id\t\tStatus\n");
    fclose(filePointer);
}

void writeDataToStatusFile(ProcessDetails_t Data, const char status[], int t)
{
    FILE *filePointer;
    filePointer = fopen("./Files/status.txt", "a");
    if (filePointer == NULL)
    {
        printErrorMessage("\nUnable To Update Status File...\n");
    }
    fprintf(filePointer, "%013d\t\t%010d\t\t%s\n", t, Data.processId, status);
    fclose(filePointer);
}
void writeHeadersToProcessesFile()
{
    FILE *filePointer;
    filePointer = fopen("./Files/processes.txt", "w");
    if (filePointer == NULL)
    {
        printErrorMessage("\nUnable To Update Status File...\n");
    }
    fprintf(filePointer, "Process Id\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurn Around Time\t\tWaiting Time\t\tResponse Time\n");
    fclose(filePointer);
}
void writeDataToProcessesFile(ProcessDetails_t Data)
{
    FILE *filePointer;
    filePointer = fopen("./Files/processes.txt", "a");
    if (filePointer == NULL)
    {
        printErrorMessage("\nUnable To Update Status File...\n");
    }
    fprintf(filePointer, "%010d\t\t%012d\t\t%010d\t\t%015d\t\t%016d\t\t%012d\t\t%013d\n", Data.processId, Data.arrivalTime, Data.burstTime1, Data.completionTime, Data.turnAroundTime, Data.waitingTime, Data.responseTime);
    fclose(filePointer);
}

#endif