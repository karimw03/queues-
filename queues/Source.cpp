#include "queue.h"
#include "queueDef.h"
#include "queueException.h"
#include "queueNode.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Queue<int> testQueue;
	Queue<int> s;
	
	for (int i = 1; i <= 10; i++)
		testQueue.enqueue(i);
	
	cout << "Printing queue: " << endl;
	testQueue.print();
	
	cout << "Printing reversed queue: " << endl;
	testQueue.reverse();
	testQueue.print();
	
	cout << "Printing the front of the queue: " << endl;
	int x = 0;
	testQueue.getFront(x);
	cout << x << endl;

	cout << "The size of this queue is: " << testQueue.countElements() << endl;

	cout << "Searching for even elements: " << endl;
	for (int i = 0; i <= 10; i++) {
		if (i % 2 == 0) {
			if (testQueue.find(i))
				cout << "Item not found: " << i << endl;
			else
				cout << "Item found: " << i << endl;
		}
	}

	cout << "Printing assigned queue: " << endl;
	s = testQueue;
	s.print();

	cout << "Printing emptied queue: " << endl;
	testQueue.makeEmpty();
	testQueue.print();

}