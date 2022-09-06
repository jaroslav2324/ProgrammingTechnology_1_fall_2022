#include <iostream>

#include "Vector.h"

int main() {

	Vector<int> vec;

	vec.pushBack(1);
	vec.pushBack(2);
	vec.pushBack(3);
	vec[1] = 5;
	vec.popBack();
	std::cout << vec.getSize();
}