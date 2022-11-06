#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat Robert("Robert", 2);
	Form* rrf;
	rrf = someRandomIntern.makeForm("shrubbeation", "Bender");
	std::cout << rrf->getTarget() << std::endl;
	Robert.signForm(*rrf);
	Robert.executeForm(*rrf);
	return 0;
}