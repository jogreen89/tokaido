// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "ready_queue.h"
#include "fcfs.h"

#define MAIN 66
#define SUB  60

void output(char*, int, char*);
void printLine(int);
void summaryBlock(int, int, int);

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cout << "Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n";
        return 0;
    } 

    int *a = processInputFile(argv[1]);
    std::queue<PCB*> q = buildProcessQueue(a);

    if (strcmp(argv[2], "FCFS") == 0) {
        output(argv[2], q.size(), argv[1]);
        struct timeval turn_start, turn_stop;                     // turnaround time
        turn_start.tv_usec = 0; turn_stop.tv_usec = 0;
        gettimeofday(&turn_start, NULL);
        operateFCFS(q);
        gettimeofday(&turn_stop, NULL);
        turn_time = ((stop.tv_sec - start.tv_sec) * 1000000 +
            stop.tv_usec - start.tv_usec);
        summaryBlock(10, 10, turn_time);
    }

    else if (strcmp(argv[2], "RR") == 0)
        std::cout << "Do RR" << std::endl;
    else if (strcmp(argv[2], "SJF") == 0)
        std::cout << "Do SJF" << std::endl;
    else
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
