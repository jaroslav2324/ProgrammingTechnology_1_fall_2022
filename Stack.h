#include "Queue.h"

#include "StructureTypes.h"


class Stack: public Queue{

    public:
    void pushBack(int element);
    int popBack();
};
