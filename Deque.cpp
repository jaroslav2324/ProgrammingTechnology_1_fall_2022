#include "Deque.h"

Deque::Deque(){
    cout << "Deque constructor called" << endl;
    type = TYPE_DEQUE;
}

Deque::Deque(const Deque& deque){
    cout << "Deque copy constructor called" << endl;
    type = deque.type;

    if (intVector != nullptr)
        delete intVector;
    intVector = nullptr;

    intVector = new Container(*deque.intVector);
}

Deque::~Deque(){
    cout << "Deque destructor called" << endl;
    if (intVector != nullptr)
        delete intVector;

    intVector = nullptr;
}

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

void Deque::menu(){

    while(1){

        cout << "1 - add element to the beginning of deque"      << endl 
             << "2 - add element to the end of deque"            << endl 
             << "3 - delete element from the beginning of deque" << endl
             << "4 - delete element from the end of deque"       << endl 
             << "5 - print deque"                                << endl
             << "b - go back"                                    << endl;

        char c;
        cin >> c;
        clearTerminal();

        switch(c){

            case '1':
            {
                int element;
                element = enterInt();
                pushFront(element);
            }
                clearTerminal();
                break;

            case '2':
            {
                int element;
                element = enterInt();
                pushBack(element);
            }
                clearTerminal();
                break;

            case '3':
            {
                int element = popFront();
                clearTerminal();
                break;
            }
            case '4':
            {
                int element = popBack();
                clearTerminal();
                break;
            }
            case '5':

                print();
                getchar();
                clearTerminal();
                break;

            case 'b':

                clearTerminal();
                return;

            default:
            
                cout << "Wrong key" << endl;
                getchar();
                clearTerminal();
        }
    }
}