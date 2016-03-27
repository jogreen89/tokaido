// pcb.h
//
// A Linked-List (simple) implementation of the 
// Process Control Block that simulates the behavior
// of different scheduling algorithms.
#ifndef PCB_H
#define PCB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class PCB {
private:
    enum PROCESS_STATE { FINISHED, RUNNING, STOPPED };
    int  _process_num;
    PCB *_next;
public:
    PCB();
    ~PCB();
    int generateProcessNumber();
};

PCB::PCB() {
    PROCESS_STATE = STOPPED;
    _process_num = generateProcessNumber();
}    

int PCB::generateProcessNumber() {
    srand (time(NULL));
    int x = rand() % 10 + 1; 
    return x; 
}

#endif
