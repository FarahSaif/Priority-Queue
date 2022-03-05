/***************************************************************************************
 * Main.cpp
 * 
 * Testing PriorityQueue.   
 ***************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"

using namespace std; 

int main()
{
    // random seed
    srand(time(NULL));

    // Create Binary Heap
    PriorityQueue pq; 

    // push random elements
    cout << "Inserting into Binary Heap: " << endl;
    for(int i=0; i<10; i++) {
        int value = rand() % 100;
        cout << "Inserting " << value << " into Binary Heap" << endl;
        pq.enqueue(value);
    }
    cout << endl;

    // Remove and print the heap
    while(!pq.isEmpty()) {
        cout << "Top Element is: " << pq.dequeue() << endl; 
    }

    return 0;
}