#include "Queue.h"

Queue::Queue(){
    //cout << "Queue constructor called" << endl;
	intVector = new Container<int>;
}

Queue::Queue(const Queue& queue){
    //cout << "Queue copy constructor called" << endl;
    type = queue.type;

    if (intVector != nullptr)
        delete intVector;
    intVector = nullptr;

    intVector = new Container(*queue.intVector);
}

Queue::~Queue(){
    //cout << "Queue destructor called" << endl;
    if (intVector != nullptr)
	    delete intVector;
    
    intVector = nullptr;
}

int Queue::size(){
    return intVector->getSize();
}

void Queue::write(std::fstream& file){

    file << size() << std::endl;

    for (int i = 0; i < size(); i++){
        int elm = intVector->operator[](i);
        file << elm << std::endl;
    }
}

void Queue::read(std::fstream& file){

    int size;
    file >> size;

    int elm;
    for (int i = 0; i < size; i++){
        file >> elm;
        intVector->pushBack(elm);
    }  
}

void Queue::print(){

	for (int i = 0; i < size(); i++)
		std::cout << intVector->operator[](i) << " ";
		std::cout << std::endl;
}

void Queue::menu(){
    //TODO throw exception

}

int Queue::getType(){
    return type;
}