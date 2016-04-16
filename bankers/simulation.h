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

    for (int i = 0; i < s->_m; i++) {
        s->_available[i] = res[i];
        // printf("s->_available[i] : %d\n", s->_available[i]);
    }
    return *s;
}

Simulation setAllocation(Simulation *s, int *res) {
    int i = 0, j = 0, k = 0;

    for (i = 0; i < s->_n; i++) {
        s->_allocation = new (std::nothrow) int*[s->_n];
        for (j = 0; j < s->_m; j++) {
            s->_allocation[i] = new (std::nothrow) int[s->_m];
            s->_allocation[i] = &res[k];
            // printf("s->_allocation[%d] : %d\n", k, *s->_allocation[i]);
            k++;
        }
    }
    
    return *s;
}

Simulation setMax(Simulation *s, int *res) {
    int i = 0, j = 0, k = 0;

    for (i = 0; i < s->_n; i++) {
        s->_max = new (std::nothrow) int*[s->_n];
        for (j = 0; j < s->_m; j++) {
            s->_max[i] = new (std::nothrow) int[s->_m];
            s->_max[i] = &res[k];
            // printf("s->_max[%d] : %d\n", k, *s->_max[i]);
            k++;
        }
    }

    return *s;
}

#endif
