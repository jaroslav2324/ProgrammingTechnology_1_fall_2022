#include "Stack.h"


void Stack::pushBack(int element){
    intVector->pushBack(element);
}

int Stack::popBack(){
    return intVector->popBack();
}
