#include "util.h"

int enterInt(){

    int num;

    cout << "Enter int number" << endl;
    cin >> num;

    while (!(cin.good())){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong number! Try once again!" << endl; 
        cout << "Enter int number" << endl;
        cin >> num;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

void clearTerminal(){
    system("clear");
}