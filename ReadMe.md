# OS + OOP Assignment

### Brief Explaination

1. While Running, Application prompts for Simulation Time, Scheduling Algorithm, Time Quantum in case of Round Robin Algorithm and No Of Processes.
2. Simulation time is the number of milli seconds the Simulator will run the process.
3. Scheduling Algo's will one of these FCFS, SRTF and RR
4. Simulator will calls The [Process_Creator](Classes/Process_Creator.h) Class. This Class will Create the Processes using Process Class and then appends them to an Array.
5. Processes will be created by some random arrival Time and Burst Time.
6. Depending on the Scheduling Algorithm [Scheduler](Classes/Scheduler.h) Class will call the Scheduling Algorithm Function, i.e, one of FCFS, SRTF, RR.
7. At the End 2 Text files will be created i) [status.txt](Files/status.txt) and ii) [processes.txt](Files/process.txt)
8. [status.txt](Files/status.txt) contains the state of the Processes in Ready Queue at each milli second.
9. [processes.txt](Files/process.txt) contains the properties(Arrival Time, Burst Time, Completion Time, Turn Around Time, Waiting Time and Response Time) of the all the Processes.

#### [Classes](Classes)

1. **[Process](Classes/Process.h)**:The data members of this class will store process id, arrival time in the ready queue, CPU burst time, completion time, turn around time, waiting time, and response time. The member functions of this class will assign values to the data members and print them. Constructor is also used to assign values.
2. **[Process_Creator](Classes/Process_Creator.h)**: This class will create an array of processes and assign a random arrival time and burst time to each process.
3. **[Scheduler](Classes/Scheduler.h)**: This class will implement the scheduling algorithm. The class will maintain a ready queue of infinite capacity (i.e., any number of processes can be accommodated in the queue). The ready queue is implemented using the min-Heap data structure where the highest priority process will be the root. The priority of the process will depend on the scheduling algorithm.Three scheduling algorithms are implemented, viz., First Come First Serve (FCFS), Shortest Remaining Time First (SRTF), and Round Robin. While runningthe program, the user will be asked the choice of scheduling algorithm.
4. **[Simulator](Classes/Simulator.h)**: This class will start the simulation. If the simulation time is 1000 milliseconds and arrival time and burst time of a process are in terms of milliseconds then the class will run a ‘for’ loop from t=0 to 1000. At each iteration, the class will execute all the necessary functions and capture the required values.
   For Each millisecond [status.txt](Files/status.txt) will be printed with status of the processes in Ready Queue.

#### Step Wise Execution

1. Main Program will prompt for Simulation Time, Scheduling Algorithm, Time Quantum in case of Round Robin Algorithm and Number of Processes.
2. Then it will write the Headers to [status.txt](Files/status.txt) and [processes.txt](Files/process.txt) files.
3. An Instance of Simulator Class will be Created with the Data Required by Simulator Object.
4. Now Simulator will start the Implementation by Creating an Instance of [Process_Creator](Classes/Process_Creator.h) Class and [Scheduler](Classes/Scheduler.h) Class.
5. [Scheduler](Classes/Scheduler.h) will Create an Instance of [FCFS Class](Classes/FCFS.h) or [SRTF Class](Classes/SRTF.h) or [RR Class](Classes/RR.h) based on Scheduling Algorithm.
6. Each of these will run a loop for simulationTime iterations.
7. In Each iteration Arrival of Processes will be checked, i.e, If current Simulation Time is equal to Arrival Time of a Process then that Processes will be pushed into the Ready Queue and then prints the status as **Arrived** in the [status.txt](Files/status.txt) file.
8. After Pushing the Process, Now It will check the Burst Time, If Burst Time is not equal to 0 then it will reduce the burst time by 1 unit in each iteration and Prints the status as **Running** in the [status.txt](Files/status.txt) file.
9. If Burst time is 0 then it will pop the process from the Ready Queue and It will start the Running of the new Process. Then, It will print the status as **Exit** for the Completed Process and **Running** for the new Process in the [status.txt](Files/status.txt) file. It will also print the [processes.txt](Files/process.txt) with Properties of Completed Process.
10. If the Simulation Time is Completed, then It will Prints the Properties of the all the processes in the Ready Queue in [processes.txt](Files/process.txt).

#### FCFS Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is arrival Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the [status.txt](Files/status.txt)
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
7. If its Burst time is greater than 0 then Running will be written to the [status.txt](Files/status.txt).
8. If the Simulation Time Stops then Program Exits.
9. It's a Non-Preemptive Algorithm.
10. So, once Processes is running it will exit only after completion.

#### SRTF Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is burst Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the [status.txt](Files/status.txt)
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
7. If its Burst time is greater than 0 then Running will be written to the [status.txt](Files/status.txt).
8. If the Simulation Time Stops then Program Exits.
9. It's a Preemptive Algorithm.
10. So, once Process is running, if another process will less burst came to ready state then this process will be preepted and second process will be set as running.

#### RR Algorithm

1. FCFS class will maintain a Ready Queue of infinite size and it appends a process to the Ready Queue when the current simulation time and is equal to the Process's Arrival Time.
2. Ready Queue is a min heap where the priority key is arival Time.
3. So For Every Second the Process in the top of the min heap will be taken.
4. Based on the Burst Time Status of the File will be written in the [status.txt](Files/status.txt)
5. If its Burst time is 0 then Exit will be written and then all other properties will be calculated and then those will be written to the Processes.txt
6. After that Process will be popped out from the ready Queue and then next process state will be running.
7. If its Burst time is greater than 0 then Running will be written to the [status.txt](Files/status.txt).
8. If the Simulation Time Stops then Program Exits.
9. It's a Preemptive Algorithm.
10. So, once Process is running, it will run for time Quantum Units and after that Process will be Preepted and CPU will be given to the Next Process in the Queue.
