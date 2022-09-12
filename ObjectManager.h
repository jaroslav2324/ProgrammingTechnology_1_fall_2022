#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

template <typename T>
class ObjectManager {
public:
	/*modes: r, w, a(read, write, append)*/
	ObjectManager(std::string filePath, char mode);
	~ObjectManager();

	void writeObject(T* object);
	void writeObject(T& object);
	void writeObjects(T** objects, int amount);
	void writeObjects(T* objects, int amount);
	void readObject(T* copyHereObject);
	void readObject(T& copyHereObject);
	void readObjects(T** copyHereArrayOfObjects, int amount);
	void readObjects(T* copyHereArrayOfObjects, int amount);
	void writeInt(int x);
	int readInt();

	void truncFile();

private:
	void openFile();

	std::string filePath;
	char mode;
	std::fstream file;
};

template <typename T>
ObjectManager<T>::ObjectManager(std::string filePath, char mode) {
	ObjectManager::filePath = filePath;
	ObjectManager::mode = mode;

	openFile();
}

template <typename T>
ObjectManager<T>::~ObjectManager() {
	if (file.is_open())
		file.close();
}

template <typename T>
void ObjectManager<T>::truncFile() {

	if (file.is_open())
		file.close();
	//clear file
	file.open(filePath.c_str(), std::ios::trunc | std::ios::out);
	file.close();

	openFile();
}

template <typename T>
void ObjectManager<T>::openFile() {

	if (mode != 'r' && mode != 'w' && mode != 'a')
		cout << "NO SUCH MODE FOR FILE!!!" << endl;

	switch (mode) {
	case 'w':
		file.open(filePath.c_str(), std::ios::out);
		break;
	case 'r':
		file.open(filePath.c_str(), std::ios::in);
		break;
	case 'a':
		file.open(filePath.c_str(), std::ios::out | std::ios::app);
		break;
	}

	if (!file.is_open())
		cout << "NO FILE " << filePath << " WAS OPENED. DOES THIS FILE EXISTS?" << endl;
}

template <typename T>
void ObjectManager<T>::writeObject(T* object) {
	object->write(file);
}

template <typename T>
void ObjectManager<T>::writeObject(T& obejct) {
	obejct.write(file);
}

template <typename T>
void ObjectManager<T>::writeObjects(T** objects, int amount) {

	for (int i = 0; i < amount; i++)
		objects[i]->write(file);
}

template <typename T>
void ObjectManager<T>::writeObjects(T* objects, int amount) {

	for (int i = 0; i < amount; i++)
		objects[i].write(file);
}

template <typename T>
void ObjectManager<T>::readObject(T* copyHereObject) {

	copyHereObject->read(file);
}

template <typename T>
void ObjectManager<T>::readObject(T& copyHereObject) {

	copyHereObject.read(file);
}

template <typename T>
void ObjectManager<T>::readObjects(T** copyHereArrayOfObjects, int amount) {

	for (int i = 0; i < amount; i++)
		copyHereArrayOfObjects[i]->read(file);
}

template <typename T>
void ObjectManager<T>::readObjects(T* copyHereArrayOfObjects, int amount) {

	for (int i = 0; i < amount; i++)
		copyHereArrayOfObjects[i].read(file);
}

template <typename T>
void ObjectManager<T>::writeInt(int x){

	file << x << endl;
}

template <typename T>
int ObjectManager<T>::readInt(){

	int x;
	file >> x;
	return x;
}