// circular_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms. Based on
// Aho et al. 1987 Data Structures.
// 2016 (c) zubernetes
#ifndef CIRCULAR_QUEUE_H 
#define CIRCULAR_QUEUE_H 


#include "pcb.h"

class CircularQueue {
private:
    PCB *_head;
    PCB *_tail;
public:
    CircularQueue();
    ~CircularQueue();

    void MAKENULL();
    int  FRONT();
    int  EMPTY();
    int  ENQUEUE(PCB*);
    int  DEQUEUE();
};

CircularQueue::CircularQueue() {
    /* Empty Queue */
    _head = NULL;
    _tail = NULL;
}

CircularQueue::~CircularQueue() {
    /* Deallocate the memory */
    /* for CircularQueue     */
    delete _head;
    delete _tail;
}

#endif
