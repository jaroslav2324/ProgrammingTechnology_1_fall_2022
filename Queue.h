#include <fstream>

#include "Vector.h"

template <typename T>
class Queue{
public:
	Queue();
	~Queue();
	virtual void write(std::fstream& file) = 0;
	virtual void read(std::fstream& file) = 0;

	int size();

protected:
	Container<T>* objectVector;
};

template <typename T>
Queue<T>::Queue(){
	objectVector = new Container<T>;
}

template <typename T>
Queue<T>::~Queue(){
	delete objectVector;
}

template <typename T>
int Queue<T>::size(){
    return objectVector.getSize();
}

