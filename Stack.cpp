#include "Stack.h"

Stack::Stack(){
    type = TYPE_STACK;
}


void Stack::pushBack(int element){
    intVector->pushBack(element);
}

int Stack::popBack(){
    return intVector->popBack();
}

void Stack::menu(){

    while(1){

        cout << "1 - add element to stack"      << endl 
             << "2 - delete element from stack" << endl 
             << "3 - print stack"               << endl
             << "b - go back"                   << endl;

        char c;
        cin >> c;
        clearTerminal();

        switch(c){

            case '1':
            {
                int element;
                element = enterInt();
                pushBack(element);
            }
                clearTerminal();
                break;

            case '2':

                popBack();
                clearTerminal();
                break;

            case '3':

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
