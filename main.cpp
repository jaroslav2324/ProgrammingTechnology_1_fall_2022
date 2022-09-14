#include <iostream>

using std::cout;
using std::endl;

#include "util.h"
#include "Keeper.h"
#include "Queue.h"
#include "Container.h"

int main() {

    Keeper<Queue> keeper("input.txt", "output.txt");
    keeper.menu();
}