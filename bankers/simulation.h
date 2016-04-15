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
    printf("Set Allocation.\n");

    for (int i = 0; i < s->_n; i++) 
        s->_allocation = new (std::nothrow) int*[s->_n];
        for (int j = 0; j < s->_m; j++) 
            s->_allocation[i] = new (std::nothrow) int[s->_m];
    
    return *s;
}

Simulation setMax(Simulation *s, int *res) {
    printf("Set Max.\n");

    for (int i = 0; i < s->_n; i++)
        s->_allocation = new (std::nothrow) int*[s->_n];
        for (int j = 0; j < s->_m; j++)
            s->_allocation[i] = new (std::nothrow) int[s->m];

    return *s;
}

#endif
