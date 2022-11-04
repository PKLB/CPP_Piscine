#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat toto("yoyo", 150);
	std::cout << toto;
	toto.downGrade();
	toto.upGrade();
	toto.upGrade();
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