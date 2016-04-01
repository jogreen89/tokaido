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
std::vector<PCB*>  buildRRQueue(int*);
std::queue<PCB*>  buildFCFSQueue(int*);
std::queue<PCB*>  buildSJFQueue(int*);
std::vector<PCB*> findMinArrival(std::vector<PCB*>); 
std::vector<PCB*> findMinBurst(std::vector<PCB*>);

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

std::vector<PCB*> buildRRQueue(int *a) {
    std::vector<PCB*>  v;

    for (int j = 0; j < getMaxCount(); j++) {
        PCB *p = new PCB();
        p->setProcessID(a[j]);
        j++;
        p->setArrivalTime(a[j]);
        j++;
        p->setBurstSize(a[j]);
        v.push_back(p);
    }

    return v;
}

std::queue<PCB*> buildSJFQueue(int *a) {
    std::vector<PCB*>  v;
    std::vector<PCB*>::iterator it;
    std::queue<PCB*> r;
    int count = 0;

    for (int j = 0; j < getMaxCount(); j++) {
        PCB *p = new PCB();
        p->setProcessID(a[j]);
        j++;
        p->setArrivalTime(a[j]);
        j++;
        p->setBurstSize(a[j]);
        v.push_back(p);
    }

    v = findMinBurst(v);
    for (it = v.begin(); it != v.end(); it++) {
        r.push(v[count]);
        count++;
    }
    
    return r;
}

std::queue<PCB*> buildFCFSQueue(int *a) {
    std::vector<PCB*>  v;
    std::vector<PCB*>::iterator it;
    std::queue<PCB*> r;
    int count = 0;

    for (int j = 0; j < getMaxCount(); j++) {
        PCB *p = new PCB();
        p->setProcessID(a[j]);
        j++;
        p->setArrivalTime(a[j]);
        j++;
        p->setBurstSize(a[j]);
        v.push_back(p);
    }

    v = findMinArrival(v);

    for (it = v.begin(); it != v.end(); it++) {
        r.push(v[count]);
        count++;
    }
    
    return r;
}

std::vector<PCB*> findMinBurst(std::vector<PCB*> v) {
    int j = 0;
    bool swapped = true;
    PCB *tmp = new PCB();
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < v.size() - j; i++) {
            if (v[i]->getBurstSize() > v[i+1]->getBurstSize()) {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                swapped = true;
            }
        }
    }
    return v;
}

std::vector<PCB*> findMinArrival(std::vector<PCB*> v) {
    int j = 0;
    bool swapped = true;
    PCB* tmp = new PCB();
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < v.size() - j; i++) {
            if (v[i]->getArrivalTime() > v[i+1]->getArrivalTime()) {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                swapped = true;
            }
        }
    }
    return v;
} 

#endif
