/***************************************************************************************
 * BinaryHeap.h
 * 
 * Declaration of BinaryHeap as a MaxHeap to serve the Priority Queue Implementation. 
 ***************************************************************************************/
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <cstdlib>

using namespace std;

const int FRONT = 0;

class BinaryHeap
{
public:

	/** Constructor with default parameter of 100 elements to alloate the 
     * underlying array. 
     */
	BinaryHeap(int mSize = 100);

	/** Insert new element into the Heap **/
	void insert(const int);

	/** Helper function to check if the heap is empty **/
	bool isEmpty() const;

	/** Function to remove the maximum element from the heap **/
	int remove();

    // Check the first element on top of the heap. 
    int top() const; 

private:
	int * heap;
	int size;
	int capacity;

	/** Find the location/index of parent node of a given position **/
	int parent(int) const;

	/** Find the location/index of Left child node of a given position **/
	int left(int) const;

	/** Find the location/index of Right child node of a given position **/
	int right(int) const;

    /** Check if given node is a leaf node at a given position **/
    bool isLeaf(int pos) const;

	/** Helper function to heapify the Heap to maintain the order **/
	void heapify(int);

	/** Helper utility to grow the size of heap array if needed **/
	void grow();

	/** helper function to maintain the heap order **/
	void perculate();

    /** Function to swap two elements of the Heap **/
    void swap(int, int);
};
#endif
