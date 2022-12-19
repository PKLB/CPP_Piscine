#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string target);
		RobotomyRequestForm(string name, string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm& src);

		void 	execute(Bureaucrat const & executor) const;
		void 	execute(int grade, string name) const;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& src);
