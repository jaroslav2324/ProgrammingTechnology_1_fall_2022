#include "Vector.h"
#include "ObjectManager.h"
#include "StructureTypes.h"
#include "Deque.h"
#include "List.h"
#include "Stack.h"


template <typename T>
class Keeper {
public:
	Keeper(std::string readPath, std::string writePath);
	~Keeper();

	void menu();

private:

	void spawnObject(int type);
	void deleteChosenObject();

    void write();
    void read();

	Container<T> objectsVector;
	ObjectManager<T>* objectWriter;
	ObjectManager<T>* objectReader;

	int numChosenContainer = 0;
};


template <typename T>
Keeper<T>::Keeper(std::string readPath, std::string writePath){
	objectReader = new ObjectManager<T>(readPath, 'r');
	objectWriter = new ObjectManager<T>(writePath, 'w');
}

template <typename T>
Keeper<T>::~Keeper(){
	delete objectReader;
	delete objectWriter;
}

template <typename T>
void Keeper<T>::spawnObject(int type){



    switch (type){
    
    case StructureTypes::TYPE_DEQUE:
    {
        Deque deq;
        objectsVector.pushBack(deq);
        break;
    }

    case StructureTypes::TYPE_LIST:
    {
        List list;
        objectsVector.pushBack(list);
        break;
    }

    case StructureTypes::TYPE_STACK:
    {
        Stack stack;
        objectsVector.pushBack(stack);
        break;
    }
    
    default:
        //TODO throw exception
        break;
    }
    
}

template <typename T>
void Keeper<T>::deleteChosenObject(){
    objectsVector.popByIndex(numChosenContainer);
}


template <typename T>
void Keeper<T>::read(){

    int size = objectReader->readInt();

    T obj;

    for (int i = 0; i < size; i++){
    objectReader->readObject(obj);
    objectsVector.pushBack(obj);
    }
}

template <typename T>
void Keeper<T>::write(){

    objectWriter->writeInt(objectsVector.getSize());
    
    for (int i = 0; i < objectsVector.getSize(); i++)
        objectWriter->writeObject(objectsVector[i]);
}

template <typename T>
void Keeper<T>::menu(){

	    while(1){

        cout << "1 - choose container"        << endl 
             << "2 - work with container"     << endl 
             << "3 - print chosen container"  << endl 
             << "4 - create container"        << endl 
             << "5 - delete chosen container" << endl 
             << "6 - print container types"   << endl 
             << "e - exit"                    << endl;
 
        char c;
        cin >> c;
        clearTerminal();

        switch(c){

            case '1':
            {
				cout << "Enter container index" << endl;
                int index;
                index = enterInt();
				//TODO check if exists
				numChosenContainer = index;

            }
                clearTerminal();
                break;

            case '2':

				(objectsVector.operator[](numChosenContainer)).menu();
                clearTerminal();
                break;

            case '3':

				(objectsVector.operator[](numChosenContainer)).print();
				getchar();
                clearTerminal();
                break;

            case '4':

                cout << "Enter container type" << endl;
                cout << "1 - List"  << endl 
                     << "2 - Stack" << endl 
                     << "3 - Deque" << endl ;
                {
                    int type;
                    type = enterInt();
                    switch (type)
                    {
                    case TYPE_LIST:
                        spawnObject(TYPE_LIST);
                        break;
                    case TYPE_STACK:
                        spawnObject(TYPE_STACK);
                        break;
                    case TYPE_DEQUE:
                        spawnObject(TYPE_DEQUE);
                        break;

                    default:
                        //TODO throw exception
                    }
                }
                clearTerminal();
                break;

            case '5':

            //TODO add try
            deleteChosenObject();
            break;

            case '6':

            for (int i = 0; objectsVector.getSize(); i++){

                type = objectsVector[i].getType();

                switch (type)
                {
                case TYPE_LIST:
                    cout << "LIST" << endl;
                    break;

                case TYPE_STACK:
                    cout << "STACK" << endl;
                    break;

                case TYPE_DEQUE:
                    cout << "DEQUE" << endl;
                    break;
                
                default:
                    break;
                }
            }
            
            getchar();

            break;

            case 'e':

                clearTerminal();
                return;

            default:
            
                cout << "Wrong key" << endl;
                getchar();
                clearTerminal();
        }
    }
}