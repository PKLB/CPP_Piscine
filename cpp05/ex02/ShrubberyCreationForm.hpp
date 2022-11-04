#pragma once
#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string src);
		ShrubberyCreationForm(string name, string src);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);

		void 	execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& src);
