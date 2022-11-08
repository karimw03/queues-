#ifndef queueException_h
#define queueException_h
#include <string>
using std::string;

class QueueException {
public:
	QueueException(const string& err) : error(err) {}
	string error;
};

#endif