// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "fcfs.h"
#include "sjf.h"
#include "rr.h"

#define MAIN 66
#define SUB  60

void output(char*, int, char*);
void printLine(int);
void summaryBlock(int, int, int);

int main(int argc, char **argv) {
    int turn_time = 0;

    if (argc < 2) {
        std::cout << "Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n";
        return 0;
    } 

    if (strcmp(argv[2], "FCFS") == 0 ||
        strcmp(argv[2], "fcfs") == 0) {
        int *a = processInputFile(argv[1]);
        std::queue<PCB*> q = buildFCFSQueue(a);
        output(argv[2], q.size(), argv[1]);
        struct timeval turn_start, turn_stop;               // turnaround time
        turn_start.tv_usec = 0; turn_stop.tv_usec = 0;
        gettimeofday(&turn_start, NULL);

        int avg_time = operateFCFS(q);

        gettimeofday(&turn_stop, NULL);
        turn_time = ((turn_stop.tv_sec - turn_start.tv_sec) * 1000000 +
            turn_stop.tv_usec - turn_start.tv_usec);
        summaryBlock(avg_time, avg_time, turn_time);

    } else if (strcmp(argv[2], "SJF") == 0 || 
               strcmp(argv[2], "sjf") == 0) {
        int *a = processInputFile(argv[1]);
        std::queue<PCB*> q = buildSJFQueue(a);
        output(argv[2], q.size(), argv[1]);
        struct timeval turn_start, turn_stop;               // turnaround time
        turn_start.tv_usec = 0; turn_stop.tv_usec = 0;
        gettimeofday(&turn_start, NULL);

        int avg_time = operateSJF(q);

        gettimeofday(&turn_stop, NULL);
        turn_time = ((turn_stop.tv_sec - turn_start.tv_sec) * 1000000 +
            turn_stop.tv_usec - turn_start.tv_usec);
        summaryBlock(avg_time, avg_time, turn_time);
    } else if (strcmp(argv[2], "RR") == 0 ||
               strcmp(argv[2], "rr") == 0) {
        int *a = processInputFile(argv[1]);
        std::vector<PCB*> v = buildRRQueue(a);
        output(argv[2], v.size(), argv[1]);
        struct timeval turn_start, turn_stop;               // turnaround time
        turn_start.tv_usec = 0; turn_stop.tv_usec = 0;
        gettimeofday(&turn_start, NULL);

        int avg_time = operateRR(v,2);

        gettimeofday(&turn_stop, NULL);
        turn_time = ((turn_stop.tv_sec - turn_start.tv_sec) * 1000000 +
            turn_stop.tv_usec - turn_start.tv_usec);
        summaryBlock(avg_time, avg_time, turn_time);
    } else
        std::cout << "Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n";
    return 0;
}

void output(char* s, int n, char* in) {
    std::string line;
    std::cout << "Scheduling algorithm: " << s << std::endl <<
        "Total " << n << " tasks are read from \"" << in <<
        "\". press \'enter\' to start...";
    std::getline(std::cin, line);
    if (line.empty()) {
        printLine(MAIN);
    } else {
        std::cout << "Project 2 Exiting" << std::endl;
    }
    
}

void printLine(int l) {
    if (l == MAIN)
        std::cout << "====================================================================\n";
    else if (l == SUB)
        std::cout << "==============================================================\n";
    else
        return;
}

void summaryBlock(int wait_time, int resp_time, int turn_time) {
    printLine(SUB);
    std::cout << "Average cpu usage       : 100.00 %" << std::endl;
    std::cout << "Average waiting time    : " << wait_time << std::endl;
    std::cout << "Average response time   : " << resp_time << std::endl;
    std::cout << "Average turnaround time : " << turn_time << std::endl;
    printLine(SUB);
}
