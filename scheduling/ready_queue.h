// ready_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms.
// 2016 (c) zubernetes
#ifndef READY_QUEUE_H 
#define READY_QUEUE_H 

#include "pcb.h"

class ReadyQueue {
private:
    std::queue<PCB*> *_ready_queue;
public:
    ReadyQueue();
    ~ReadyQueue();
    void Enqueue(PCB*);
    void Dequeue();
};

ReadyQueue::ReadyQueue() {
    
}

ReadyQueue::~ReadyQueue() {
    printf("No errors here...\n");
}

void ReadyQueue::Enqueue(PCB *p) {
    _ready_queue->push(p);    
}

void ReadyQueue::Dequeue(void) {
    _ready_queue->pop();
}

#endif
