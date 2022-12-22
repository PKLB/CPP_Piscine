#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> myFirstVector;
	for (int i = 0; i < 5; i++)
		myFirstVector.push_back(i);
	try{
		easyfind(myFirstVector, 4);
		easyfind(myFirstVector, 10);
	}
	catch(const std::exception& n){	
		std::cout << "No occurence found!\n";
    }
	return 0;
}