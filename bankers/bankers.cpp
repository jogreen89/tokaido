// bankers.cpp
// A C++ implementation of the Bankers
// Algorithm for a simulation of
// process-resource allocation.
#include "reader.h"
#include <iostream>
#include <string>

#define CMDLINE 2
#define BUF_SIZE 50

void print_simulation(Simulation*);
void print_need(Simulation*);
int  safety_algorithm(Simulation*, char*, bool);

int main (int argc, char **argv) {
    int i;
    _Bool deadlock;
    bool run = false;
    char action[BUF_SIZE], *filename, *request_v;
    struct Simulation *s;
    std::string str = " ";

    if (argc < 2) {
      std::cout << "Usage: banker [inputFile]" << std::endl;
      return 1;
    }

    filename = argv[1];
    s = readInFile(filename);
    print_simulation(readInFile(filename));

    while (deadlock) {
        deadlock = safety_algorithm(s, (char*)str.c_str(), run);

        if (deadlock) {
            int request_len = s->_m;
            int input = 0;
            std::cout << "Any request<Y/N>:";
            std::cin >> action;
            if (strcmp(action, "Y") == 0 || strcmp(action, "y") == 0) {
                std::cout << "please input request in format <pid> X X X X:";
                // flush stdin
                getchar();
                std::getline (std::cin, str);
                run = true;
            }
            else
                break;
        }
    }
    free(s);

    return 0;
}

void print_need(Simulation *s) {
   int i, j;

    std::cout << "Need:" << std::endl;
    for (i = 0; i < s->_n; i++) {
        for (j = 0; j < s->_m; j++) {
            std::cout << s->_max[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void print_simulation(Simulation *s) {
    int i, j;

    std::cout << "Available:" << std::endl;
    for (i = 0; i < s->_m; i++) {
        std::cout << s->_available[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Max:" << std::endl;
    for (i = 0; i < s->_n; i++) {
        for (j = 0; j < s->_m; j++) {
            std::cout << s->_max[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Allocation" << std::endl;
    for (i = 0; i < s->_n; i++) {
        for (j = 0; j < s->_m; j++) {
            std::cout << s->_allocation[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    print_need(s);
}

int safety_algorithm(Simulation *s, char *request, bool run) {
    int allocation[s->_n][s->_m], max[s->_n][s->_m], available[s->_m];
    int alloc[3] = {0, 0, 0};
    int maxres[s->_m], running[s->_m], safe = 0, safe_sequence[s->_n];
    int count = 0, i, j, exec, r = s->_m, p = s->_n, k = 0;
    _Bool deadlock = 1;

    // Intialization of running
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }

    // Initialization of alloc[], the currently allocated resources.
    for (i = 0; i < r; i++)
        alloc[i] = 0;

    // Setup Available Table
    for (i = 0; i < r; i++) {
        available[i] = s->_available[i];
    }

    // Setup Resource Table
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            allocation[i][j] = s->_allocation[i][j];
        }
    }

    // If a Request Edge is made, modify Allocation Table
    // for the process making a new request.
    if (run) {
        int pid;
        int res = 0;
        int i = 0;
        std::cout << "This is your Request Edge: " << request << std::endl;
        while (request[i] != '\0') {
            std::cout << request[i] << std::endl;
            if (i == 0) {
                pid = atoi(&request[i]);
            }

            if (request[i] != ' ') {
                res = atoi(&request[i]);
               if (allocation[pid][i-1] > request[i])
                    allocation[pid][i-1] = allocation[pid][i-1] - res;
               else
                    allocation[pid][i-1] = res - allocation[pid][i-i];
            }
            i++;
        }
    }

    // Setup Max Table
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            max[i][j] = s->_max[i][j];
        }
    }

    // Setup "Currently" Allocated Table
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            alloc[j] += allocation[i][j];
        }
    }

    while (count != 0) {
        safe = 0;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max[i][j] - allocation[i][j] > available[j]) {
                        exec = 0;
                        break;
                    }
                }

                if (exec) {
                    safe_sequence[k] = i + 1;
                    k++;
                    running[i] = 0;
                    count--;
                    safe = 1;
                    for (j = 0; j < r; j++) {
                        available[j] += allocation[i][j];
                    }

                    break;
                }
            }
        }
        if (!safe) {
            for (i = 0; i < s->_n; i++) {
                std::cout << "P" << i << " is deadlocked!" << std::endl;
                deadlock = 0;
            }
            break;
        }
    }
    if (deadlock) {
        std::cout << "we are safe!" << std::endl;
        std::cout << "Safe sequence: <";
        for (i = 0; i < p; i++) {
            if (i == p - 1)
                std::cout << "P" << safe_sequence[i];
            else
                std::cout << "P" << safe_sequence[i] << ", ";
        }
        std::cout << ">" << std::endl;
        return 1;
    } else
        return 0;
}
