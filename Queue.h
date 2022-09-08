#include <iostream>
#include <fstream>

#include "Vector.h"
#include "utility.h"

using std::cin;
using std::cout;
using std::endl;

class Queue{
public:
	Queue();
	~Queue();
	void write(std::fstream& file);
	void read(std::fstream& file);

	int size();

	void print();
	virtual void menu() = 0;

protected:
	Container<int>* intVector;
};

