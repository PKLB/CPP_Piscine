#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat toto("LowLvlBureaucrat", 160);
	std::cout << toto;
	toto.upGrade();
	toto.upGrade();
	toto.downGrade();
	toto.downGrade();
	toto.downGrade();
	std::cout << toto;

	Bureaucrat yoyo("HighLvlBureaucrat", 3);
	std::cout << yoyo;
	yoyo.upGrade();
	yoyo.upGrade();
	yoyo.upGrade();
	yoyo.downGrade();
	std::cout << yoyo;
	return 0;
}