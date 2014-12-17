#include "heap.h"

template<class ItemType>
class hQueue //this is a pQueue shell for heap
{
public:
	hQueue();
	~hQueue();
	bool IsEmpty();
	//Pre-Condition: Queue is intialized
	//Function: Returns true if nothing is in the Queue
	//Post-Condition: returns bool true if Queue is empty

	void MakeEmpty();
	//Pre-Condition: Queue is initialized
	//Function: removes all items from the Queue
	//Post-Condition: Queue is empty

	void EnQueue(int key, ItemType data);
	//Pre-Condition: Queue is initialzed
	//Function: Adds a node to the Queue
	//Post-Condition: Queue has one more node

	void DeQueue(heapNode<ItemType> &item);
	//Pre-Condition: Queue is initialized
	//Function: removes a node from the Queue
	//Post-Condition: Queue has one less node

	unsigned int LengthIs();
	//Pre-Condition: Queue is initialized
	//Function: returns the length of the Queue
	//Post-Condition: length variable is returned

	void display();
	//Pre-Condition: heap is initialized
	//Function: displays contents (key) of the array
	//Post-Condition: key of array is displayed

	void sort();
	//Pre-Condition: heap is initialized
	//Function: sorts the array from the heap
	//Post-Condition: array is sorted

	void flipOrder();
	//Pre-Condition: heap is initialized
	//Function: reverses the order of the array (also makes it  heap again)
	//Post-Condition: array order is reversed

private:
	heap<ItemType> heap1;
};

template<class ItemType>
hQueue<ItemType>::hQueue()
{

}
template<class ItemType>
hQueue<ItemType>::~hQueue()
{

}

template<class ItemType>
bool hQueue<ItemType>::IsEmpty()
{
	return(heap1.isEmpty());
}

template<class ItemType>
void hQueue<ItemType>::MakeEmpty()
{
	heap1.makeEmpty();
}

template<class ItemType>
void hQueue<ItemType>::EnQueue(int key, ItemType data)
{
	heap1.insertNode(key, data);
}

template<class ItemType>
void hQueue<ItemType>::DeQueue(heapNode<ItemType> &item)
{
	heap1.retrieveTop(item);
}

template<class ItemType>
unsigned int hQueue<ItemType>::LengthIs()
{
	return(heap1.getLength());
}

template<class ItemType>
void hQueue<ItemType>::display()
{
	heap1.display();
}

template<class ItemType>
void hQueue<ItemType>::sort()
{
	heap1.heapSort();
}

template<class ItemType>
void hQueue<ItemType>::flipOrder()
{
	heap1.flipOrder();
}