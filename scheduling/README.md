# Project 2: CPU Scheduling Simulation

This program simulates how the CPU schedules processes and how processes
are completed using an abstract data type PCB (Process-Control-Block). There
are three CPU scheduling algorithms simulated in this program.

1. FCFS (First-Come-First-Serve)
2. SJF  (Shortest-Job-First)
3. RR   (Round-Robin)

To run the program, run the following command at the command line:
  * ./proj2 input_file [FCFS|RR|SJF] [time_quantum]

Example usage:
```bash
    ./proj2 input_file FCFS
    ./proj2 input_file RR 2
    ./proj2 input_file SJF
```
Files:

1. proj2.cpp - Primary class that handles control flow and logic of usage pattterns of the CPU Scheduling Simulation. Also contains functions for formatted output/input.
2. ready_queue.h - Builds an STL queue of PCB classes that simulate CPU scheduling. Each CPU scheduling algorithm is built differently to support the STL queue and operate appropriately.
3. fcfs.h - Contains function to schedule work using the FCFS algorithm. 
4. sjf.h - Contains function to schedule work using the SJF algorithm. 
4. rr.h - Contains function to schedule work using the RR algorithm. 
5. Makefile - Entering "make" at the command line will build the project ready for usage within the local directory.



