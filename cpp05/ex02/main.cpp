#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm dossier("fileName", "target");
	RobotomyRequestForm mossier("opela", "pleberr");
	// std::cout << dossier;
	Bureaucrat Robert("Robert", 150);

	// Robert.executeForm(dossier);
	Robert.setGrade(4);
	Robert.signForm(mossier);
	// Robert.signForm(dossier);
	// Robert.executeForm(dossier);
	Robert.executeForm(mossier);
	// std::cout << dossier;
	return 0;
}