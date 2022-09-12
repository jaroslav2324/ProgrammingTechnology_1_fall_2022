#include <iostream>

#include "Keeper.h"

int main() {
    Keeper<Queue> keeper("input.txt", "output.txt");
    keeper.menu();
}