/***************************************************************************************
 * PriorityQueue.h
 * 
 * Declaration of PriorityQueue based on the Binary Heap class.  
 ***************************************************************************************/
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "BinaryHeap.h"

using namespace std; 

class PriorityQueue
{
    public:

        // Function to Enqueue into the Priority queue
        void enqueue(const int); 

        // Functiont o dequeue from the Priority Queue
        int dequeue(); 

        // Function to see the Front element
        int front() const; 

        // Check if the queue is empty
        bool isEmpty() const; 

    private:
        BinaryHeap heap; 
};

#endif
