// ready_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms.
// 2016 (c) zubernetes
#ifndef READY_QUEUE_H 
#define READY_QUEUE_H 

class ReadyQueue {
private:
    PCB *head;
    PCB *tail;
public:
    PCB();
    ~PCB();
    int Enqueue(PCB*);
    int Dequeue();
};

#endif
