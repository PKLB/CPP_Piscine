#include <iostream>
#include <vector>
#include <algorithm>
#include "Span.hpp"

int main(void)
{
	Span sp = Span(501);
	std::vector<int> test(50);
	for (int i = 0; i < 50; i++)
		test.push_back(i);
	try {
		sp.addNumbers(test.begin(), test.end());
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e){
		std::cout << "invalid span.\n";
	}
	return 0;
}