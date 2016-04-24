// simulation.h
//
// A simple data structure holding the
// Bankers Algorithm data.
// 2016 (c) zubernetes
#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct Simulation Simulation;

struct Simulation {
    int    _n;
    int    _m;
    int*   _available;
    int**  _allocation;
    int**  _max;
};

#endif
