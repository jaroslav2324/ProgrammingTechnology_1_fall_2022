

template <typename T>
class Vector {
public:
	Vector();
	~Vector();
	T& operator[](int index);
	void pushBack(T object);
	T popBack();
	int getSize();
private:
	void resizeMemory();
	int memorySize = 1;
	int size = 0;
	T* objectsArray;
};

template <typename T>
Vector<T>::Vector() {
	objectsArray = new T[memorySize];
}

template <typename T>
Vector<T>::~Vector() {
	for (int i = 0; i < size; i++)
		delete objectsArray[i];
}

template <typename T>
T& Vector<T>::operator[](int index) {
	return (objectsArray + index);
}

template <typename T>
void Vector<T>::resizeMemory() {

	memorySize *= 2;
	T** newArray = new T * [memorySize];

	for (int i = 0; i < size; i++)
		newArray[i] = objectsArray[size];

	delete objectsArray;
	objectsArray = newArray;
}

template <typename T>
int Vector<T>::getSize() {
	return size;
}

template <typename T>
void Vector<T>::pushBack(T object) {

	T obj(object);

	if (size == memorySize)
		resizeMemory();

	objectsArray[size] = obj;
}

template <typename T>
T Vector<T>::popBack() {

	T obj(*objectsArray[size - 1]);
	delete objectsArray[size - 1];

	return obj;
}