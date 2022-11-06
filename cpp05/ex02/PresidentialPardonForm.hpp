#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string src);
		PresidentialPardonForm(string name, string src);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm& src);

		void 	execute(Bureaucrat const & executor) const;
		void 	execute(int grade, string name) const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& src);
