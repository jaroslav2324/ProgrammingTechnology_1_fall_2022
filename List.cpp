#include "List.h"

    void List::pushBack(int element){
        intVector->pushBack(element);
    }
    void List::pushByIndex(int element, int index){
        intVector->pushByIndex(element, index);
    }
    void List::pushFront(int element){
        intVector->pushFront(element);
    }
    int List::popBack(){
        return intVector->popBack();
    }
    int List::popByIndex(int index){
        return intVector->popByIndex(index);
    }
    int List::popFront(){
        return intVector->popFront();
    }
