#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm dossier("fileName", "target");
	// std::cout << dossier;
	Bureaucrat Robert("Robert", 150);

	dossier.execute(Robert);
	Robert.setGrade(4);
	dossier.execute(Robert);
	std::cout << dossier;
	return 0;
}