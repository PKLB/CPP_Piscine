#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
using std::string;

Intern::Intern(){
	std::cout << "Intern has been created" << std::endl;
}

Intern::Intern(const Intern &src){
	std::cout << "Intern has been created" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern has been destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern& src){
	return *this;
}

Form	*Intern::makeForm(string formName, string targetForm){
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
					return (new RobotomyRequestForm(targetForm));
				}
				case 2:
				{
					std::cout << "Intern creates " << formName << std::endl;
					return (new ShrubberyCreationForm(targetForm));
				}
				case 3:
				{
					std::cout << "Intern creates " << formName << std::endl;
					return (new PresidentialPardonForm(targetForm));
				}
			}
		}
	}
	std::cout << "The intern couldn't the form you asked for, he created a PresidentialPardonForm hoping it was the form you asked for.\n";
	return (new PresidentialPardonForm(targetForm));
}

