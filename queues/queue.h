#ifndef queue_h
#define queue_h
#include"queueNode.h"
#include "queueException.h"

template <class T>
class Queue {
public:
	Queue();

	Queue(const Queue& rhs);

	~Queue();

	Queue& operator=(const Queue& rhs);

	bool isEmpty() const;

	void enqueue(const T& newItem);

	void dequeue();

	void dequeueAndSave(T& queueFront) ;

	void getFront(T& queueFront)const ;

	void print() const;

	void reverse();

	int countElements();

	void makeEmpty();

	bool find(T& data);

private:
	QueueNode<T>* backPtr;
	QueueNode<T>* frontPtr;
};

#endif