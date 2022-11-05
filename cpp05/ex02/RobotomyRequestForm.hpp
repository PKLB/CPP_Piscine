#pragma once
#include "Form.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string src);
		RobotomyRequestForm(string name, string src);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm& src);

		void 	execute(Bureaucrat const & executor) const;
		void 	execute(int grade, string name) const;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& src);
