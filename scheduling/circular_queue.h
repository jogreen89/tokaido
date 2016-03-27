// circular_queue.h
//
// A basic circular queue implementation to
// simulate CPU scheduling algorithms. Based on
// Aho et al. 1987 Data Structures.
// 2016 (c) zubernetes
#ifndef CIRCULAR_QUEUE_H 
#define CIRCULAR_QUEUE_H 

#include <stdio.h>

class CircularQueue {
private:
    PCB *head;
    PCB *tail;
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
    *head = NULL;
    *tail = NULL;
}

#endif
