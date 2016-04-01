# Project 2: CPU Scheduling Simulation

This program simulates how the CPU schedules processes and how processes
are completed using an abstract data type PCB (Process-Control-Block). There
are three CPU scheduling algorithms simulated in this program.

1. FCFS (First-Come-First-Serve)
2. SJF  (Shortest-Job-First)
3. RR   (Round-Robin)

To run the program, run the following command at the command line:
    *./proj2 input_file [FCFS|RR|SJF] [time_quantum]

Example usage:
```bash
    ./proj2 input_file FCFS
    ./proj2 input_file RR 2
    ./proj2 input_file SJF
```
