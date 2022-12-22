#include <iostream>
#include <vector>
#include <algorithm>
#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e){
		std::cout << "invalid span.\n";
	}
	return 0;
}