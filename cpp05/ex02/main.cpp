#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm dossier("Coulée verte", "Projet de verdure");
	RobotomyRequestForm gossier("ple-berr", "Projet de lobotomie");
	PresidentialPardonForm mossier("Mbappe", "Le pardon de Macron");
	Bureaucrat Robert("Robert", 1);
	std::cout << Robert;

	std::cout << dossier;
	std::cout << gossier;
	std::cout << mossier;
	Robert.executeForm(dossier);
	Robert.setGrade(150);
	dossier.beSigned(Robert);
	gossier.beSigned(Robert);
	mossier.beSigned(Robert);
	Robert.executeForm(dossier);
	Robert.executeForm(gossier);
	Robert.executeForm(mossier);
	Robert.setGrade(1);
	dossier.beSigned(Robert);
	gossier.beSigned(Robert);
	mossier.beSigned(Robert);
	Robert.executeForm(dossier);
	Robert.executeForm(gossier);
	Robert.executeForm(mossier);
	std::cout << dossier;
	std::cout << gossier;
	std::cout << mossier;
	return 0;
}