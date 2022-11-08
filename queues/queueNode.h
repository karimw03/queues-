#ifndef queueNode_h
#define queueNode_h
#include <iostream>

template <class Object>
class QueueNode
{
public:
	QueueNode(const Object& e = Object(), QueueNode* n = NULL): item(e), next(n) {}
	Object item;
	QueueNode* next;
};


#endif