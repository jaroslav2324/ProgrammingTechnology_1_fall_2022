#include "List.h"

List::List(){
    cout << "List constructor called" << endl;
    type = TYPE_LIST;
}

List::List(const List& list){
    cout << "List copy constructor called" << endl;
    type = list.type;

    if (intVector != nullptr)
        delete intVector;
    intVector = nullptr;

    intVector = new Container(*list.intVector);
}

List::~List(){
    cout << "List destructor called" << endl;
    if (intVector != nullptr)
        delete intVector;

    intVector = nullptr;
}

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

void List::menu(){

    while(1){

        cout << "1 - add element to the beginning of list"      << endl 
             << "2 - add element in list by index"              << endl 
             << "3 - add element to the end of list"            << endl 
             << "4 - delete element from the beginning of list" << endl
             << "5 - delete element from list by index"         << endl 
             << "6 - delete element from the end of list"       << endl 
             << "7 - print list"                                << endl
             << "b - go back"                                   << endl;

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
                cout << "Enter element to add" << endl;
                int element = enterInt();
                cout << "Enter position where to add" << endl;
                int index = enterInt();

                pushByIndex(element, index);
            }
                clearTerminal();
                break;

            case '3':

            {
                int element;
                element = enterInt();
                pushBack(element);
            }

                clearTerminal();
                break;

            case '4':
            {
                int element = popFront();
                clearTerminal();
                break;
            }
            case '5':

            {
                cout << "Enter position where to delete" << endl;
                int index = enterInt();

                popByIndex(index);
            }
                clearTerminal();
                break;

            case '6':
            {
                int element = popBack();
                clearTerminal();
                break;
            }
            case '7':

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