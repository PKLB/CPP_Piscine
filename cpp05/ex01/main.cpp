#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form dossier("Démission de ple-berr");
	std::cout << dossier;

	Bureaucrat Roger("Roger", 76);
	Bureaucrat Albert("Albert", 8);
	std::cout << Roger;
	std::cout << Albert;
	dossier.beSigned(Roger);
	dossier.beSigned(Albert);
	Roger.upGrade();
	Roger.upGrade();
	dossier.beSigned(Roger);
	std::cout << dossier;

	return 0;
}