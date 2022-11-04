#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form dossier("Démission de ple-berr");
	std::cout << dossier;

	Bureaucrat Roger("Roger", 12);
	Bureaucrat Albert("Albert", 8);
	std::cout << Roger;
	std::cout << Albert;
	dossier.setSignGrade(10);
	dossier.setExecGrade(50);
	dossier.beSigned(Roger);
	dossier.beSigned(Albert);
	std::cout << dossier;

	return 0;
}