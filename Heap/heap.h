template<class ItemType>
struct heapNode
{
	unsigned int key;
	ItemType data;
};

template<class ItemType>
class heap
{
public:
	heap();
	~heap();
	//heap(const heap<ItemType> &acopy);
	//operator= (const heap &acopy);

	bool isFull();
	//Pre-Condition: 
	//Function: checks is heap is full
	//Post-Condition: returns true if heap is full

	bool isEmpty();
	//Pre-Condition: 
	//Function: check if heap is empty
	//Post-Condition: returns true is heap is empty

	void insertNode(int key, ItemType data);
	//Pre-Condition: 
	//Function: adds given data to array
	//Post-Condition: new data is added to array

	void retrieveTop(heapNode<ItemType> &data);
	//Pre-Condition: 
	//Function: removes the top data and 'returns' it
	//Post-Condition: heap root is swapped and data is 'returned'

	void makeEmpty();
	//Pre-Condition: 
	//Function: empties the array
	//Post-Condition: array length is set to zero

	unsigned int getLength();
	//Pre-Condition:
	//Function: returns the length of the array
	//Post-Condition: array length is returned

	void display();
	//Pre-Condition:
	//Function: displays contents (key) of the array
	//Post-Condition: key of array is displayed

	void heapSort();
	//Pre-Condition:
	//Function: sorts the array from the heap
	//Post-Condition: array is sorted

	void flipOrder();
	//Pre-Condition: heap is sorted
	//Function: reverses the order of the array (also makes it  heap again)
	//Post-Condition: array order is reversed

private:
	heapNode<ItemType>* heapArray;
	unsigned int length;

	void reheapUp(int root, int bottom);
	//Pre-Condition: 
	//Function: remakes the heap when a new node is added
	//Post-Condition: now qualifies as a heap again

	void reheapDown(int root, int bottom);
	//Pre-Condition: 
	//Function: remakes the heap when a node is removed
	//Post-Condition: now qualifies as a heap again

	void swap(int first, int second);
	//Pre-Condition: 
	//Function: swaps the data of two array spots
	//Post-Condition: data of two spots is swapped

	void resize();
	//Pre-Condition: 
	//Function: upsizes the array
	//Post-Condition: array is made larger
};

//non-class operators:
#pragma region operators

template<class ItemType>
bool operator > (heapNode<ItemType> left, heapNode<ItemType> right)
{
	return(left->key > right.key);
}

template<class ItemType>
bool operator >= (heapNode<ItemType> left, heapNode<ItemType> right)
{
	return(left->key >= right.key);
}

template<class ItemType>
bool operator < (heapNode<ItemType> left, heapNode<ItemType> right)
{
	return(left.key < right.key);
}

template<class ItemType>
bool operator <= (heapNode<ItemType> left, heapNode<ItemType> right)
{
	return(left.key <= right.key);
}

template<class ItemType>
bool operator == (heapNode<ItemType> left, heapNode<ItemType> right)
{
	return(left.key == right.key);
}
#pragma endregion

//in-class functions:
template<class ItemType>
heap<ItemType>::heap()
{
	length = 0;
	heapArray = new heapNode<ItemType>[10];
}

template<class ItemType>
heap<ItemType>::~heap()
{
	length = 0;
	delete[] heapArray;
}

template<class ItemType>
bool heap<ItemType>::isEmpty()
{
	return(length == 0);
}

template<class ItemType>
bool heap<ItemType>::isFull()
{
	return(false);
}

template<class ItemType>
void heap<ItemType>::insertNode(int key, ItemType data)
{
	if(!isFull())
	{
		heapNode<DataType>* temp = new heapNode<DataType>;
		temp->key = key;
		temp->data = data;
		length++;
		heapArray[length - 1] = *temp;
		reheapUp(0, length - 1);
	}
}

template<class ItemType>
void heap<ItemType>::retrieveTop(heapNode<ItemType> &data)
{
	if(!isEmpty())
	{
		data = heapArray[0];
		swap(0, length - 1);
		length--;
		reheapDown(0, length - 1);
	}
}

template<class ItemType>
void heap<ItemType>::reheapDown(int root, int bottom)
{
	int maxChild;
	int leftChild = root * 2 + 1;
	int rightChild = root * 2 + 2;//swap names

	if(leftChild <= bottom)//we are not at end of array
	{
		if(leftChild == bottom)//last element in array
		{
			maxChild = leftChild;
		}
		else
		{
			if(heapArray[leftChild] <= heapArray[rightChild])//is left or right child larger
			{
				maxChild = rightChild;
			}

			else
			{
				maxChild = leftChild;
			}
		}

		if(heapArray[root] < heapArray[maxChild])
		{
			swap(root, maxChild);
			reheapDown(maxChild, bottom);
		}
	}
}

template<class ItemType>
void heap<ItemType>::reheapUp(int root, int bottom)
{
	int parent;

	if(bottom > root)
	{
		parent = (bottom - 1) / 2;
		if(heapArray[parent] < heapArray[bottom])
		{
			swap(parent, bottom);
			reheapUp(root, parent);
		}
	}
}

template<class ItemType>
void heap<ItemType>::swap(int first, int second)
{
	heapNode<ItemType> temp = heapArray[first];
	heapArray[first] = heapArray[second];
	heapArray[second] = temp;
}

template<class ItemType>
void heap<ItemType>::resize()
{
	heapNode* temp = new heapNode[length + 10];
	
	for(int i = 0; i < length; i++)
	{
		temp[i] = heapArray[i];
	}

	delete[] heapArray;
	heapArray = temp;
}

template<class ItemType>
unsigned int heap<ItemType>::getLength()
{
	return(length);
}

template<class ItemType>
void heap<ItemType>::makeEmpty()
{
	length = 0;
}

template<class ItemType>
void heap<ItemType>::heapSort()
{
	for(int tempLength = length - 1; tempLength > 0; tempLength--)
	{
		swap(0, tempLength );
		reheapDown(0, tempLength - 1 );
	}
}

template<class ItemType>
void heap<ItemType>::display()
{
	heapNode<ItemType> temp;
	for(unsigned int i = 0; i < length; i++)
	{
		temp = heapArray[i];
		cout << temp.key << " ";// << temp.data << endl;
	}
	cout << ":end of array" << endl;
}

template<class ItemType>
void heap<ItemType>::flipOrder()
{
	for(unsigned int i = 0; i < length / 2; i++)
	{
		swap(i, length - i - 1 );
	}
}
