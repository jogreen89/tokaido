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
    } else {
        if (strcmp (argv[1], "FCFS") == 0) {
            printf("FCFS\n"); 
            scanf("%s", buffer);
            delay = atoi(buffer);
            for (i = 0; i < delay; i++) {
                printf("<system time %d> process %d is running\n", i, delay);
                usleep(1000);
            }
        } else if (strcmp (argv[1], "RR") == 0)
            printf("RR\n");
        else if (strcmp (argv[1], "SJF") == 0)
            printf("SJF\n");
        else
            printf("Usage: proj2 input_file [FCFS|RR|SJF] [time_quantum]\n");
        return 0;
    }
}
