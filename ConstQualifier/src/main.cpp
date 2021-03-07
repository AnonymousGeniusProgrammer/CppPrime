#include <iostream>
#include "main.hpp"

int main()
{
	extern const int bufSize;
	std::cout << "External variable bufSize: " << bufSize << std::endl;

	int i = 42;
	const int& r1 = i;
	const int& r2 = 42;
	const int& r3 = r1 * 2;
	std::cout << "Const reference of i = 42 is, r1 = " << r1 << std::endl;
	std::cout << "After changing i to ++i = " << ++i  << ", r1 = " << r1 << std::endl;
}