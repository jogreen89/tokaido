#ifndef SIMULATION_H
#define SIMULATION_H

// C++ library
#include <new>

struct Simulation {
    int   _n;
    int   _m;
    int*  _available;
    int** _allocation;
    int** _max;
};

void printSimulationSize(Simulation*);
Simulation setAvailable(Simulation*, int*);
Simulation setAllocation(Simulation*, int*);
Simulation setMax(Simulation*,int*);

void printSimulationSize(Simulation *s) {
    printf("Print Simulation Size.\n");
    printf("Number of n processes: %d Number of m resources: %d\n", s->_n, s->_m);
}

Simulation setAvailable(Simulation *s, int *res) {
    int *available;

    printf("Set Available.\n");
    printf("new (std::nothrow) int[s->_m]: %d\n", s->_m);

    available = new (std::nothrow) int[s->_m];
    s->_available = available;

    int len = s->_m;
    for (int i = 0; i < len; i++) {
        s->_available[i] = res[i];
        printf("s->_available[i] : %d\n", s->_available[i]);
    }
    return *s;
}

Simulation setAllocation(Simulation *s, int *res) {
    s->_allocation = new (std::nothrow) int*[s->_n];

    printf("Set Allocation.\n");
    printf("new (std::nothrow) int[s->_n][s->_m]: n-%d m-%d\n", s->_n, s->_m);
    
    int len = s->_n * s->_m;
    for (int i = 0; i < len; i++) {
        s->_allocation[i] = new (std::nothrow) int[s->_m];
        printf("s->_allocation[%d] : %d\n", i, *s->_allocation[i]);
    }
    return *s;
}

#endif
