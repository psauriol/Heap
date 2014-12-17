#include "heapQueue.h"
#include "linearQueue.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
typedef int DataType; 


void main()
{
	hQueue<DataType> hQueue1;

	string command = "";
	cout << "Available commands are insert, retrieve, sort, display, empty, and test" << endl;
	while (command != "Quit")
	{
		cout << "Enter a command: ";
		cin.sync();
		cin.clear();
		cin >> command;

		if(command == "insert" || command == "i")
		{
			int key;
			DataType data;
			cout << "Enter data priority" << endl;
			cin >> key;
			cout << "Enter data" << endl;
			cin >> data;

			hQueue1.EnQueue(key, data);
		}
		else if(command == "retrieve" || command == "r")
		{
			heapNode<DataType>* newNode = new heapNode<DataType>;
			hQueue1.DeQueue(*newNode);
			if(!hQueue1.IsEmpty())
			{
				cout << newNode->data << " "
				<< newNode->key << endl;
			}
			else
			{
				cout << "Array is empty" << endl;
			}
		}
		else if(command == "empty" || command == "e")
		{
			hQueue1.MakeEmpty();	
		}
		else if(command == "sort" || command == "s")
		{
			hQueue1.sort();
		}
		else if(command == "display" || command == "d")
		{
			hQueue1.display();

			//cout << time(NULL) << " time" << endl;
			//cout << clock() << " clock" << endl;
		}
		else if(command == "flip")
		{
			hQueue1.flipOrder();
		}
		else if(command == "test" || command == "t")
		{
			hQueue<DataType> hQueue2;
			

			unsigned int testNum;
			cout << "How many values would you like to test for?:";
			cin >> testNum;

			int tClock = (int)clock();
			cout << clock() << " current clock" << endl;
			for(unsigned int i = 0; i <= testNum; i++)
			{
				hQueue2.EnQueue(i, i * -1);
			}
			cout << (int)clock() - tClock << " hQueue enQueue" << endl;

			heapNode<DataType>* temp2 = new heapNode<DataType>;
			while(!hQueue2.IsEmpty())
			{
				hQueue2.DeQueue(*temp2);
			}
			cout << (int)clock() - tClock << " hQueue DeQueue" << endl;
			//hQueue2.~hQueue();

			Queue<DataType> lQueue2;
			tClock = (int)clock();
			for(unsigned int i = 0; i <= testNum; i++)
			{
				lQueue2.EnQueue(i, i);
			}
			cout << (int)clock() - tClock << " lQueue enQueue" << endl;


			DataType temp3;
			while(!lQueue2.IsEmpty())
			{
				lQueue2.DeQueue(temp3);
			}
			cout << (int)clock() - tClock << " lQueue DeQueue" << endl;
			cout << "test";
			//hQueue2.~hQueue();
		}
	}//end while
}//end main