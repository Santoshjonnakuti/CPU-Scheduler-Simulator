# OS + OOP Assignment

### Brief Explaination

1. While Running, Application prompts for Simulation Time, Scheduling Algorithm, Time Quantum in case Round Robin Algorithm and No Of Processes.
2. Simulation time is the number of milli seconds the Simulator will run the process.
3. Scheduling Algo's will one of these FCFS, SRTF and RR
4. Simulator will calls The Process_Creator Class. This Class will Create the Processes using Process Class and then appends them to an Array.
5. Processes will be created by some random arrival Time and Burst Time.
6. Depending on the Scheduling Algorithm Scheduler Class will call the Scheduling Algorithm Function, i.e, one of FCFS, SRTF, RR.

#### FCFS Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is arrival Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the status.txt
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
8. If its Burst time is greater than 0 then Running will be written to the status.txt.
9. If the Simulation Time Stops then Program Exits.
10. Its a Non-Preemptive Algorithm.
11. So, once Processes is running it will exit only after completion.

#### SRTF Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is burst Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the status.txt
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
8. If its Burst time is greater than 0 then Running will be written to the status.txt.
9. If the Simulation Time Stops then Program Exits.
10. Its a Preemptive Algorithm.
11. So, once Process is running, if another process will less burst came to ready state then this process will be preepted and second process will be set as running.


#### RR Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is arival Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the status.txt
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
8. If its Burst time is greater than 0 then Running will be written to the status.txt.
9. If the Simulation Time Stops then Program Exits.
10. Its a Preemptive Algorithm.
11. So, once Process is running, it will run for time Quantum Units and after that Process will  be Preepted and CPU will be given to the Next Process in the Queue.
