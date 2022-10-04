#include <exception>

#include "Container.h"
#include "ObjectManager.h"
#include "StructureTypes.h"
#include "Deque.h"
#include "List.h"
#include "Stack.h"
#include "WrongFileContentErr.h"


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
	ObjectManager<T>* objectWriter = nullptr;
	ObjectManager<T>* objectReader = nullptr;

	int numChosenContainer = 0;
};


template <typename T>
Keeper<T>::Keeper(std::string readPath, std::string writePath){

    try{
	objectReader = new ObjectManager<T>(readPath, 'r');
    read();
    }
    catch(NoFileExistsError err){
        cout << "No input file exists!" << endl;
    }
    catch(WrongFileContentError err){
        cout << "Wrong values in the file. Continuing with empty keeper" << endl;
    }

    try{
	objectWriter = new ObjectManager<T>(writePath, 'w');
    }
    catch(NoFileExistsError err){}
    catch(WrongFileContentError err){}
}

template <typename T>
Keeper<T>::~Keeper(){

    write();
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
        throw std::invalid_argument("Wrong type of spawning object");
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

    for (int i = 0; i < size; i++){
        int objectType = objectReader->readInt();

        switch(objectType){
            case TYPE_DEQUE:
            {
            Deque obj;
            objectReader->readObject(obj);
            objectsVector.pushBack(obj);
            break;
            }
            case TYPE_LIST:
            {
            List obj;
            objectReader->readObject(obj);
            objectsVector.pushBack(obj);
            break;
            }
            case TYPE_STACK:
            {
            Stack obj;
            objectReader->readObject(obj);
            objectsVector.pushBack(obj);
            break; 
            }
            default:
            cout << "Wrong type of object" << endl;
            break;
            
        }
    }
}

template <typename T>
void Keeper<T>::write(){

    objectWriter->writeInt(objectsVector.getSize());
    
    for (int i = 0; i < objectsVector.getSize(); i++){

        T& object = objectsVector[i];
        objectWriter->writeInt(object.getType());
        objectWriter->writeObject(object);
    }
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
 
        char c = enterSymbol();
        
        clearTerminal();

        switch(c){

            case '1':
            {
				cout << "Enter container index" << endl;
                int index;
                index = enterInt();
				if (0 <= index && index < objectsVector.getSize())
				    numChosenContainer = index;
                else{
                    cout << "Wrong index!" << endl;
                    waitAnyKeyAndNewLine();
                }

            }
                clearTerminal();
                break;

            case '2':

                {

                if ( ! (0 <= numChosenContainer && numChosenContainer < objectsVector.getSize())){
                    cout << "No container with this index! Enter another index." << endl;
                    waitAnyKeyAndNewLine();
                    clearTerminal();
                    break;
                }

                T& objRef = objectsVector.operator[](numChosenContainer);

                if (objRef.getType() == TYPE_DEQUE){
                    Deque* deqPtr = (Deque*)(&objRef);
                    (deqPtr)->Deque::menu();
                }
                if (objRef.getType() == TYPE_LIST){
                    List* listPtr = (List*)(&objRef);
                    (listPtr)->List::menu();
                }
                if (objRef.getType() == TYPE_STACK){
                    Stack* stackPtr = (Stack*)(&objRef);
                    (stackPtr)->Stack::menu();
                }

                }

                clearTerminal();
                break;

            case '3':

				(objectsVector.operator[](numChosenContainer)).print();
				waitAnyKeyAndNewLine();
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

                    try{
                        switch (type)
                        {
                        case 1:
                            spawnObject(TYPE_LIST);
                            break;
                        case 2:
                            spawnObject(TYPE_STACK);
                            break;
                        case 3:
                            spawnObject(TYPE_DEQUE);
                            break;

                        default:
                            throw std::invalid_argument("There is no structure with this number");
                            break;
                        }
                    }
                    catch (std::invalid_argument& exc){
                        cout << exc.what() << endl;
                        waitAnyKeyAndNewLine();
                    }
                }
                clearTerminal();
                break;

            case '5':

            deleteChosenObject();
            break;

            case '6':

            for (int i = 0; i < objectsVector.getSize(); i++){

                int type = objectsVector[i].getType();

                switch (type)
                {
                case TYPE_LIST:
                    cout << i << "-" << "LIST" << endl;
                    break;

                case TYPE_STACK:
                    cout << i << "-" << "STACK" << endl;
                    break;

                case TYPE_DEQUE:
                    cout << i << "-" << "DEQUE" << endl;
                    break;
                
                default:
                    break;
                }
            }
            
            waitAnyKeyAndNewLine();
            clearTerminal();

            break;

            case 'e':

                clearTerminal();
                return;

            default:
            
                cout << "Wrong key" << endl;
                waitAnyKeyAndNewLine();
                clearTerminal();
        }
    }
}