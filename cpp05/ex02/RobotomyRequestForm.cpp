#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(): Form(0, 72, 45){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(string src): Form(src, 0, 72, 45){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(string name, string src): Form(name, src, 0, 72, 45){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):  Form(src.getName(), 0, 72, 45){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try
	{
		if (getSigned() == 0)
			throw(GradeTooLowException());
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout <<  "BrrzzrRZrzrRZzRZRrzrz.........!!\n";
		srand (time(NULL));
		int nb = rand() % 10 + 1;
		if (nb % 2 == 0)
			std::cout << getTarget() << " has been successfully robotomized !\n";
		else
			std::cout << getTarget() << " has not been robotomized !\n";
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

void 	RobotomyRequestForm::execute(int grade, string name) const{
	try
	{
		if (getSigned() == 0)
			throw(GradeTooLowException());
		if (grade > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << name << " executed " << getName() << std::endl;
		std::cout <<  "BrrzzrRZrzrRZzRZRrzrz.........!!\n";
		srand (time(NULL));
		int nb = rand() % 10 + 1;
		if (nb % 2 == 0)
			std::cout << getTarget() << " has been successfully robotomized !\n";
		else
			std::cout << getTarget() << " has not been robotomized !\n";
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& src){
	if (src.getSigned() == 0)
		os << src.getName() << " RobotomyRequestForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
	else
		os << src.getName() << " RobotomyRequestForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
    return os;
}
