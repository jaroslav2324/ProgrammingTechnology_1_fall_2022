#include "ObjectManager.h"

template <typename T>
class Container {
public:
	Container();
	~Container();
	T& operator[](int index);
	void pushBack(T object);
	void pushFront(T object);
	T popBack();
	T popByIndex(int index);
	T popFirst();
	int getSize();
	void print();

private:
friend class ObjectManager<T>;
	void resizeMemory();
	int memorySize = 1;
	int size = 0;
	T** objectsArray;
};

template <typename T>
Container<T>::Container() {
	objectsArray = new T* [memorySize];
}

template <typename T>
Container<T>::~Container() {
	for (int i = 0; i < size; i++)
		delete objectsArray[i];
}

template <typename T>
T& Container<T>::operator[](int index) {
	return *objectsArray[index];
}

template <typename T>
void Container<T>::resizeMemory() {

	memorySize *= 2;
	T** newArray = new T * [memorySize];

	for (int i = 0; i < size; i++)
		newArray[i] = objectsArray[i];

	delete objectsArray;
	objectsArray = newArray;
}

template <typename T>
int Container<T>::getSize() {
	return size;
}

template <typename T>
void Container<T>::pushBack(T object) {

	T* obj = new T(object);

	if (size == memorySize)
		resizeMemory();

	objectsArray[size] = obj;

	size += 1;
}

template <typename T>
T Container<T>::popBack() {

	if (size <= 0)
		return;

	T obj = T(*objectsArray[size - 1]);
	delete objectsArray[size - 1];
	
	size -= 1;
	return obj;
}

	template <typename T>
T Container<T>::popByIndex(int index){

	if (size <= 0)
		return;

	T obj = T(*objectsArray[index]);
	delete objectsArray[index];
	
	size -= 1;
	return obj;
}

template <typename T>
T Container<T>::popFirst(){

	if (size <= 0)
		return;

	T obj = T(*objectsArray[0]);
	delete objectsArray[0];
	
	size -= 1;
	return obj;
	
}

template <typename T>
void Container<T>::print(){

	for (int i = 0; i < size; i++)
	std::cout << *objectsArray[i] << " ";
}