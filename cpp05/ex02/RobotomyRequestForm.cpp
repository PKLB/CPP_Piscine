#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm(0, 45, 72){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(string target): AForm(target, 0, 45, 72){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(string name, string target): AForm(name, target, 0, 45, 72){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):  AForm(src.getName(), 0, 45, 72){
	std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
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
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

void 	RobotomyRequestForm::execute(int grade, string name) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
		if (grade > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << "\033[1;36m" << name << " executed " << getName() << "\033[0m" << std::endl;
		std::cout <<  "BrrzzrRZrzrRZzRZRrzrz.........!!\n";
		srand (time(NULL));
		int nb = rand() % 10 + 1;
		if (nb % 2 == 0)
			std::cout << getTarget() << " has been successfully robotomized !\n";
		else
			std::cout << getTarget() << " has not been robotomized !\n";
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& src){
	if (src.getSigned() == 0)
		os << "\033[1;34m- " << src.getName() << " RobotomyRequestForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
	else
		os << "\033[1;34m- " << src.getName() << " RobotomyRequestForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
    return os;
}
