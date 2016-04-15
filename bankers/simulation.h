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

Simulation setAvailable(Simulation*, int*);
Simulation setAllocation(Simulation*, int*);
Simulation setMax(Simulation*, int*);

Simulation setAvailable(Simulation *s, int *res) {
    s->_available = new (std::nothrow) int[s->_m]; 

    printf("Set Available.\n");

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
    
    int len = s->_n * s->_m;
    for (int i = 0; i < len; i++) {
        s->_allocation[i] = new (std::nothrow) int[s->_m];
        printf("s->_allocation[%d] : %d\n", i, *s->_allocation[i]);
    }
    return *s;
}

Simulation setMax(Simulation *s, int *res) {
    s->_max = new (std::nothrow) int*[s->_n];

    printf("Set Max.\n");
    
    int len = s->_n * s->_m;
    for (int i = 0; i < len; i++) {
        s->_max[i] = new (std::nothrow) int[s->_m];
        printf("s->_max[%d] : %d\n", i, *s->_max[i]);
    }
    return *s;
}

#endif
