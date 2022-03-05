/***************************************************************************************
 * PriorityQueue.cpp
 * 
 * Implementation of PriorityQueue based on the Binary Heap class.  
 ***************************************************************************************/

#include "PriorityQueue.h"

// Function to Enqueue into the Priority queue
void PriorityQueue::enqueue(const int value)
{
    heap.insert(value);
} 

// Functiont o dequeue from the Priority Queue
int PriorityQueue::dequeue()
{
    return heap.remove();
} 

// Function to see the Front element
int PriorityQueue::front() const
{
    return heap.top();
} 

// Check if the queue is empty
bool PriorityQueue::isEmpty() const
{
    return heap.isEmpty();
} 