// pcb.h
//
// A Linked-List (simple) implementation of the 
// Process Control Block that simulates the behavior
// of different scheduling algorithms.
#ifndef PCB_H
#define PCB_H

class PCB {
private:
    enum PROCESS_STATE { FINISHED, RUNNING, STOPPED };
    int process_num;
    PCB *next;
public:
    PCB();
    ~PCB();
};

#endif
