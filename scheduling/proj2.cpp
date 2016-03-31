// proj2.cpp
//
// CPU scheduling simulation.
// 2016 (c) zubernetes
#include "ready_queue.h"

int main(int argc, char **argv) {
    int delay = 0, i;
    char buffer[80];

    if (argc < 2) {
        printf("Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n");
        return 0;
    } 

    printf("Enter the buffer amount: ");
    scanf("%s", buffer);
    delay = atoi(buffer);
    for (i = 0; i < delay; i++) {
        printf("<system time %d> process %d is running\n", i, delay);
    }
    
    return 0;
}
