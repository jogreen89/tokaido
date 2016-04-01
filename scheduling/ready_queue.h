// ready_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms.
// 2016 (c) zubernetes
#ifndef READY_QUEUE_H 
#define READY_QUEUE_H 
#define BUF_SIZE 50

#include "pcb.h"

void              setMaxCount(int);
int               getMaxCount();
int*              processInputFile(char*);
std::queue<PCB*>  buildProcessQueue(int*);

int max_count = 0;

void setMaxCount(int x) {
    max_count = x;
}

int getMaxCount() {
    return max_count;
}

int* processInputFile(char *infile) {
    int x = 0,
        i = 0,
        y = 0,
        z = 0,
        count = 0;
    static int a[BUF_SIZE];
    std::queue<PCB*> q;
    PCB *p = new PCB();

    std::fstream f;
    f.open(infile, std::fstream::in); 

    while (f >> x) {
        a[i] = x;
        count++;
        i++;
        if (count > 2) {
            count = 0;
        }
    }
    f.close();
    setMaxCount(i);
    return &a[0];
}

std::queue<PCB*> buildProcessQueue(int *a) {
    std::queue<PCB*> q;
    int count = 0;

    for (int j = 0; j < getMaxCount(); j++) {
        PCB *p = new PCB();
        p->setProcessID(a[j]);
        j++;
        p->setArrivalTime(a[j]);
        j++;
        p->setBurstSize(a[j]);
        q.push(p);
    }

    return q;
}

#endif
