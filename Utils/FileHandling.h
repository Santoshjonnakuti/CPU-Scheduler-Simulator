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

#endif