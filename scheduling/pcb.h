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
#include <iostream>
#include <fstream>

class PCB {
private:
    int  _process_num;
    int  _burst_size;
    int  _arrival_time;
    PCB *_next;
public:
    PCB();
    ~PCB();
    void setProcessID(int);
    void setBurstSize(int);
    void setArrivalTime(int);
    void makeNull();

    int getProcessID();
    int getBurstSize();
    int getArrivalTime();
};

PCB::PCB() {
    _process_num  = 0;
    _burst_size   = 0;
    _arrival_time = 0;
}    

PCB::~PCB() {
	delete _next;
}

void PCB::setProcessID(int x) {
    _process_num = x;
}

void PCB::setBurstSize(int x) {
    _burst_size = x;
}

void PCB::setArrivalTime(int x) {
    _arrival_time = x;
}

void PCB::makeNull() {
    _process_num  = 0;
    _burst_size   = 0;
    _arrival_time = 0;
}

int PCB::getProcessID() {
    return _process_num;
}


int PCB::getBurstSize() {
    return _burst_size;
}

int PCB::getArrivalTime() {
    return _arrival_time;
}

#endif
