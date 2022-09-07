#include <fstream>

#include "Vector.h"

class Queue{
public:
	Queue();
	~Queue();
	void write(std::fstream& file);
	void read(std::fstream& file);

	int size();

	void print();

protected:
	Container<int>* intVector;
};

