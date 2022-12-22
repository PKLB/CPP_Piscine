#include <iostream>
#include <vector>
#include <algorithm>
#include "Span.hpp"

int main(void)
{
	Span sp = Span(2000);
	std::vector<int> test(0);
	for (int i = 0; i < 1000; i++)
		test.push_back(i);
	try {
		sp.addNumbers(test.begin(), test.end());
		sp.addNumber(1500);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e){
		std::cout << "invalid span.\n";
	}
	return 0;
}