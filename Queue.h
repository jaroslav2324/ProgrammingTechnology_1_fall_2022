#pragma once

#include <iostream>
#include <fstream>

#include "Vector.h"
#include "util.h"

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
	virtual void menu();

	int getType();

protected:
	Container<int>* intVector;
	int type;
};

