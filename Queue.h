#pragma once

#include <iostream>
#include <fstream>

#include "Container.h"
#include "util.h"

using std::cin;
using std::cout;
using std::endl;

class Queue{
public:
	Queue();
	Queue(const Queue& queue);
	~Queue();
	void write(std::fstream& file);
	void read(std::fstream& file);

	int size();

	void print();
	virtual void menu();

	int getType();

protected:
	Container<int>* intVector = nullptr;
	int type;
};

