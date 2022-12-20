#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
using std::string;

Intern::Intern(){
	std::cout << "Intern has been created" << std::endl;
}

Intern::Intern(const Intern &src){
	*this = src;
	std::cout << "Intern has been created" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern has been destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern&){
	return *this;
}

AForm	*Intern::makeForm(string formName, string targetForm){
	string tab[3]= {"robotomy request", "shrubbery creation", "presidential pardon"};
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (formName == tab[i])
		{
			result = i + 1;
			switch(result)
			{
				case 1:
				{
					std::cout << "Intern creates " << formName << std::endl;
					return (new RobotomyRequestForm(formName, targetForm));
				}
				case 2:
				{
					std::cout << "Intern creates " << formName << std::endl;
					return (new ShrubberyCreationForm(formName, targetForm));
				}
				case 3:
				{
					std::cout << "Intern creates " << formName << std::endl;
					return (new PresidentialPardonForm(formName, targetForm));
				}
			}
		}
	}
	std::cout << "The intern couldn't the form you asked for, he created a PresidentialPardonForm hoping it was the form you asked for.\n";
	return (new PresidentialPardonForm(formName, targetForm));
}
