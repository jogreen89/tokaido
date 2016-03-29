// ready_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms.
// 2016 (c) zubernetes
#ifndef READY_QUEUE_H 
#define READY_QUEUE_H 

// C++ STL Container 
#include <queue>

#include "pcb.h"

class ReadyQueue {
private:
    std::queue<PCB*> *_ready_queue;
public:
    ReadyQueue();
    ~ReadyQueue();
    int Enqueue(PCB*);
    int Dequeue();
};

ReadyQueue::ReadyQueue() {
    printf("No errors here...\n");
}

ReadyQueue::~ReadyQueue() {
    printf("No errors here...\n");
}

int ReadyQueue::Enqueue(PCB *p) {
    _ready_queue->push(p);    
    return 0;
}

int ReadyQueue::Dequeue() {
    _ready_queue->pop();
    return 0;
}

#endif
