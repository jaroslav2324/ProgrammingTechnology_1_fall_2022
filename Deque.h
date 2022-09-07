#include "Queue.h"

template <typename T>
class Deque: public Queue<T>{

    public:
    Deque();
    ~Deque();
    void pushBack(T element);
    void pushFront(T element);
    T popBack();
    T popFront();
    void write(std::fstream& file);
	void read(std::fstream& file);
};

template <typename T>
void Deque<T>::pushBack(T element){
    Queue<T>::objectVector->pushBack(element);
}

template <typename T>
void Deque<T>::pushFront(T element){
        Queue<T>::objectVector->pushFront(element);
}

template <typename T>
T Deque<T>::popBack(){
    return Queue<T>::objectVector->popBack();
}

template <typename T>
T Deque<T>::popFront(){
    return Queue<T>::objectVector->popFront();
}