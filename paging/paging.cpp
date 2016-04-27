// paging.cpp
//
// A simple C++ simulation of
// of page replacement algorithms commonly
// used in operating systems.
// 2016 (c) zubernetes
#include <iostream>
#include <string.h>

// #include "random.h"
#include "page_frame.h"

#define ARGS 2

void exec_fifo(void);
void exec_lru(void);
void exec_optimal(void);

int main(int argc, char **argv) {
    if (argc < ARGS)
        std::cout << "Usage: paging [fifo|lru|optimal]" << std::endl;
    if (argv[1] != NULL) {
        if (strncmp(argv[1], "FIFO", ARGS) == 0 ||
            strncmp(argv[1], "fifo", ARGS) == 0)
            exec_fifo();
        if (strncmp(argv[1], "LRU", ARGS) == 0 ||
            strncmp(argv[1], "lru", ARGS) == 0)
            exec_lru();
        if (strncmp(argv[1], "OPTIMAL", ARGS) == 0 ||
            strncmp(argv[1], "optimal", ARGS) == 0)
            exec_optimal();
    }
    return 0;
}

void exec_fifo(void) {
    std::cout << "Implementation of FIFO page replacement algorithm."
        << std::endl;
}

void exec_lru(void) {
    std::cout << "Implementation of LRU page replacement algorithm."
        << std::endl;
}

void exec_optimal(void) {
    std::cout << "Implementation of Optimal page replacement algorithm."
        << std::endl;
}
