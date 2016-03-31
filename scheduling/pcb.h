// pcb.h
//
// A Linked-List (simple) implementation of the 
// Process Control Block that simulates the behavior
// of different scheduling algorithms.
#ifndef PCB_H
#define PCB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>

class PCB {
private:
    int  _process_num;
    int  _process_size;
    PCB *_next;
public:
    PCB();
    ~PCB();
    int generatePID();
    int getPID();
};

PCB::PCB() {
    _process_num = generateProcessNumber();
}    

PCB::~PCB() {
	delete _next;
}

int PCB::generatePID() {
    srand (time(NULL));
    int x = rand() % 500 + 150;
    return x; 
}

int PCB::getPID() {
    return _process_num;
}

#endif
