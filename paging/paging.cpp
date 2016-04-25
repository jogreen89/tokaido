#include <iostream>

#define ARGS 2
void exec_fifo(void);
void exec_lru(void);
void exec_optimal(void);

int main(int argc, char **argv) {
    if (argc < ARGS) 
        std::cout << "Usage: paging [fifo|lru|optimal]" << std::endl;
    else
        std::cout << "Hello, World!" << std::endl;
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
