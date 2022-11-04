#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm dossier("Plantation d'arbres", "Amazonie");
	// std::cout << dossier;
	Bureaucrat Robert("Robert", 150);

	// dossier.execute(Robert);
	dossier.beSigned(Robert);
	Robert.setGrade(4);
	dossier.beSigned(Robert);
	// dossier.execute(Robert);
	// std::cout << dossier;
	return 0;
}