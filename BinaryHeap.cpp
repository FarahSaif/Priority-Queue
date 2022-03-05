/***************************************************************************************
 * BinaryHeap.cpp
 * 
 * Implementation of BinaryHeap as a MaxHeap to serve the Priority Queue Implementation. 
 ***************************************************************************************/
#include "BinaryHeap.h"

/** Constructor with default parameter of 100 elements to alloate the 
 * underlying array. 
 */
BinaryHeap::BinaryHeap(int mSize)
	: size(0), capacity(mSize)
{
	heap = new int[capacity + 1];
	heap[0] = 999999999;
}

/** Find the location/index of parent node of a given position **/
int BinaryHeap::parent(int pos) const
{
	return (pos-1) / 2;
}

/** Find the location/index of Left child node of a given position **/
int BinaryHeap::left(int pos) const
{
	return pos * 2 + 1;
}

/** Find the location/index of Right child node of a given position **/
int BinaryHeap::right(int pos) const
{
	return pos * 2 + 2;
}

/** Check if given node is a leaf node at a given position **/
bool BinaryHeap::isLeaf(int pos) const
{
	if (pos >= (size / 2) && pos <= size)
	{
		return true;
	}

	return false;
}

/** Function to swap two elements of the Heap **/
void BinaryHeap::swap(int x, int y)
{
	int tmp = heap[x];
	heap[x] = heap[y];
	heap[y] = tmp;
}

/** Helper function to heapify the Heap to maintain the order **/
void BinaryHeap::heapify(int pos)
{
	int lt = left(pos);
	int rt = right(pos);

	if (!isLeaf(pos)) 
	{
		if (heap[pos] < heap[lt] || heap[pos] < heap[rt]) 
		{
			if (heap[lt] > heap[rt]) 
			{
				swap(pos, lt);
				heapify(lt);
			}
			else 
			{
				swap(pos, rt);
				heapify(rt);
			}
		}
	}
}

/** Insert new element into the Heap **/
void BinaryHeap::insert(int element)
{
	if (size >= capacity)
	{
		grow();
	}

	heap[size++] = element;
	int current = size - 1;

	//maintain order
	while (current != 0 && heap[parent(current)] > heap[current])
	{
		swap(current, parent(current));
		current = parent(current);
	}

	// maintain order
	perculate();

}

void BinaryHeap::grow()
{
	//current array
	int * tmp = new int[capacity];

	//copy
	for (int i = 0; i<size; i++)
	{
		tmp[i] = heap[i];
	}

	//Resize
	capacity *= 2;
	heap = new int[capacity];

	//copy back
	for (int i = 0; i<size; i++)
	{
		heap[i] = tmp[i];
	}
}

void BinaryHeap::perculate()
{
	for (int pos = (size / 2); pos >= 0; pos--)
	{
		heapify(pos);
	}
}

int BinaryHeap::remove()
{
	if (size == 1)
	{
		size--;
		return heap[FRONT];
	}
	else
	{
		int popped = heap[FRONT];
		heap[FRONT] = heap[size-1];
		size--;
		heapify(FRONT);
		return popped;
	}
}

bool BinaryHeap::isEmpty() const
{
	return size == 0;
}

// Check the first element on top of the heap. 
int BinaryHeap::top() const
{
    return heap[FRONT];
} 