#pragma once

#include "Queue.h"

#include "StructureTypes.h"


class Stack: public Queue{

    public:
    Stack();
    Stack(const Stack& stack);
    ~Stack();
    void pushBack(int element);
    int popBack();
    void menu();
};
