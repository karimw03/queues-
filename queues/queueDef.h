#ifndef queueDef_h
#define queueDef_h
#include "queue.h"
#include "queueException.h"
#include "queueNode.h"
#include <iostream>
using std::cout;
using std::endl;

template<class T>
Queue<T>::Queue() : backPtr(NULL), frontPtr(NULL) {}

template<class T>
Queue<T>::Queue(const Queue& rhs) {
	*this = rhs;
}

template<class T>
Queue<T>::~Queue() { 
	while (!isEmpty())
		dequeue();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
	
	if (this != &rhs) {
		QueueNode<T>* r = rhs.frontPtr;
		QueueNode<T>* p =frontPtr;

		while (r) {
			enqueue(r->item);
			r = r->next;
			p = p->next;
		}
	}
	return* this;
}

template<class T>
bool Queue<T>::isEmpty() const {
	return backPtr == NULL;
}

template<class T>
void Queue<T>::enqueue(const T& newItem) {
	QueueNode<T>* newPtr = new QueueNode<T>;
	
	newPtr->item = newItem;
	newPtr->next = NULL;
	
	if (isEmpty()) 
		frontPtr = newPtr;
	else 
		backPtr->next = newPtr;
	backPtr = newPtr; 
}

template<class T>
void Queue<T>::dequeue() {
	if (isEmpty())
		throw QueueException("QueueException: empty queue, cannot dequeue");
	else { 
		QueueNode<T>* tempPtr = frontPtr;
		if (frontPtr == backPtr) {
			frontPtr = NULL;
			backPtr = NULL;
		}
		else
			frontPtr = frontPtr->next;
		tempPtr->next = NULL;
		delete tempPtr;
	}
}

template<class T>
void Queue<T>::dequeueAndSave(T& queueFront)  {
	if (isEmpty())
		throw QueueException("QueueException: empty queue, cannot dequeue");
	else { 
		queueFront = frontPtr->item;
		dequeue(); 
	}
}

template<class T>
void Queue<T>::getFront(T& queueFront) const{
	if (isEmpty())
		throw QueueException("QueueException: empty queue, cannot getFront");
	else 
			queueFront = frontPtr->item;
}

template <class T>
void Queue<T>::print() const {
	QueueNode<T>* front = frontPtr;

	while (front) {
		cout << front->item << endl;
		front = front->next;
	}
}

template <class T>
void Queue<T>::reverse(){
	QueueNode<T>* current = frontPtr;
	QueueNode<T>* after = NULL;
	QueueNode<T>* previous = NULL;
	QueueNode<T>* temp = frontPtr;

	while (current) {
		after = current->next;
		current->next = previous;
		previous = current;
		current = after;
	}

	frontPtr = backPtr;
	backPtr = temp;
}

template <class T>
int Queue<T>::countElements() {
	int counter = 0;
	while (frontPtr) {
		counter++;
		frontPtr = frontPtr->next;
	}
	return counter;
}

template <class T>
void Queue<T>::makeEmpty() {
	
	while (!isEmpty()) {
		dequeue();
		frontPtr = frontPtr->next;
	}
}

template <class T>
bool Queue<T>::find(T& data) {
	QueueNode<T>* p = frontPtr;
	
	while (p) {
		if (p->item == data)
			return true;
		p = p->next;
	}
	return false;
}

#endif 