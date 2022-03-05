/***************************************************************************************
 * Main.cpp
 * 
 * Testing PriorityQueue.   
 ***************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std; 

/***************************************************************************************
 * BinaryHeap.h
 * 
 * Declaration of BinaryHeap as a MaxHeap to serve the Priority Queue Implementation. 
 ***************************************************************************************/
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

/***************************************************************************************
 * PriorityQueue.h
 * 
 * Declaration of PriorityQueue based on the Binary Heap class.  
 ***************************************************************************************/
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


/***************************************************************************************
 * BinaryHeap.cpp
 * 
 * Implementation of BinaryHeap as a MaxHeap to serve the Priority Queue Implementation. 
 ***************************************************************************************/

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



/***************************************************************************************
 * PriorityQueue.cpp
 * 
 * Implementation of PriorityQueue based on the Binary Heap class.  
 ***************************************************************************************/

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

