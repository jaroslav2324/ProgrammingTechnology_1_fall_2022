#include "Deque.h"

void Deque::pushBack(int element){
    intVector->pushBack(element);
}

void Deque::pushFront(int element){
        intVector->pushFront(element);
}

int Deque::popBack(){
    return intVector->popBack();
}

int Deque::popFront(){
    return intVector->popFront();
}
