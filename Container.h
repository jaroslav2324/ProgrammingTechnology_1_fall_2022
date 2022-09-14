#pragma once

#include "util.h"
#include "ObjectManager.h"

template <typename T>
class Container {
public:
	Container();
	Container(const Container<T>& container);
	~Container();
	T& operator[](int index);
	void pushBack(T object);
	void pushFront(T object);
	void pushByIndex(T object, int index);
	T popBack();
	T popByIndex(int index);
	T popFront();
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
	//cout << "Container constructor called" << endl;
	objectsArray = new T* [memorySize];
}

template <typename T>
Container<T>::Container(const Container<T>& container){

    //cout << "Container copy constructor called" << endl;

	memorySize = container.memorySize;
	size = container.size;

	objectsArray = new T* [memorySize];

	for (int i = 0; i < size; i++)
		objectsArray[i] = new T(*(container.objectsArray[i]));

}

template <typename T>
Container<T>::~Container() {

	//cout << "Container destructor called" << endl;

	for (int i = 0; i < size; i++)
		delete objectsArray[i];
}

template <typename T>
T& Container<T>::operator[](int index) {
	T* objectPtr = objectsArray[index];
	T& objRef = *objectPtr;
	return objRef;
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
void Container<T>::pushByIndex(T object, int index){

	T* obj = new T(object);

	if (size == memorySize)
		resizeMemory();

	for (int i = size; i > index; i--)
		objectsArray[i] = objectsArray[i - 1];

	objectsArray[index] = obj;

	size += 1;
}

template <typename T>
void Container<T>::pushFront(T object){

	T* obj = new T(object);

	if (size == memorySize)
		resizeMemory();

	for (int i = size; i > 0; i--)
		objectsArray[i] = objectsArray[i - 1];

	objectsArray[0] = obj;

	size += 1;
}

template <typename T>
T Container<T>::popBack() {

	T clearObj;

	if (size <= 0){
		cout << "Nothing to delete!" << endl;
		waitAnyKeyAndNewLine();
		return clearObj;
	}
		
	T obj = T(*objectsArray[size - 1]);
	delete objectsArray[size - 1];

	objectsArray[size - 1] = nullptr;
	
	size -= 1;
	return obj;
}

	template <typename T>
T Container<T>::popByIndex(int index){

	T clearObj;

	if (size <= 0){
		cout << "Nothing to delete!" << endl;
		waitAnyKeyAndNewLine();
		return clearObj;
	}

	T obj = T(*objectsArray[index]);
	delete objectsArray[index];

	//shift array
	for (int i = index; i < size; i++)
		objectsArray[i] = objectsArray[i + 1];
	
	size -= 1;
	return obj;
}

template <typename T>
T Container<T>::popFront(){

	T clearObj;

	if (size <= 0){
		cout << "Nothing to delete!" << endl;
		waitAnyKeyAndNewLine();
		return clearObj;
	}

	T obj = T(*objectsArray[0]);
	delete objectsArray[0];

	for (int i = 0; i < size - 1; i++)
		objectsArray[i] = objectsArray[i + 1];
	
	size -= 1;
	return obj;
	
}

template <typename T>
void Container<T>::print(){

	for (int i = 0; i < size; i++)
	std::cout << *objectsArray[i] << " ";
}