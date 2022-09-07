#include "Queue.h"

#include "StructureTypes.h"


class List: public Queue{

    public:
    void pushBack(int element);
    void pushByIndex(int element, int index);
    void pushFront(int element);
    int popBack();
    int popByIndex(int index);
    int popFront();
};