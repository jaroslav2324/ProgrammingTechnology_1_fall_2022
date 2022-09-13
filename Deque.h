#pragma once

#include "Queue.h"

#include "StructureTypes.h"


class Deque: public Queue{

    public:
    Deque();
    Deque(const Deque& deque);
    ~Deque();
    void pushBack(int element);
    void pushFront(int element);
    int popBack();
    int popFront();
    void menu();
};

