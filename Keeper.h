#include "Vector.h"
#include "ObjectManager.h"
#include "StructureTypes.h"


template <typename T>
class Keeper {
public:
	Keeper(std::string readPath, std::string writePath);
	~Keeper();
	void spawnObject(int type);
	void deleteLastObject();
	void deleteFirstObject();
	void deleteObjectByIndex(int index);

private:
	Container<T> objectsVector;
	ObjectManager<T>* objectWriter;
	ObjectManager<T>* objectReader;
};


template <typename T>
Keeper<T>::Keeper(std::string readPath, std::string writePath){
	objectReader = new ObjectManager<T>(readPath, 'r');
	objectWriter = new ObjectManager<T>(writePath, 'w');
}

template <typename T>
Keeper<T>::~Keeper(){
	delete objectReader;
	delete objectWriter;
}

template <typename T>
void Keeper<T>::spawnObject(int type){

    switch (type)
    {
    case TYPE_DEQUE:
        Deque deq();
        objectsVector.pushBack()
        break;
    
    default:
        break;
    }
}
template <typename T>
void Keeper<T>::deleteLastObject(){

}

template <typename T>
void Keeper<T>::deleteFirstObject(){

}

template <typename T>
void Keeper<T>::deleteObjectByIndex(int index){

}

