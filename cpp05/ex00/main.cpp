#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat yoyo("popipo");
	Bureaucrat toto(yoyo);
	std::cout << toto;
	return 0;
}