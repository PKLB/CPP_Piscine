#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(string name, string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);

		void 	execute(Bureaucrat const & executor) const;
		void 	execute(int grade, string name) const;

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& src);
