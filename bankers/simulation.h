#ifndef SIMULATION_H
#define SIMULATION_H

struct Simulation {
    int n;
    int m;
};

void printSimulation(Simulation *s);

void printSimulation(Simulation *s) {
    printf("Print Simulation.\n");
    printf("%d, %d\n", s->n, s->m);
}

#endif
