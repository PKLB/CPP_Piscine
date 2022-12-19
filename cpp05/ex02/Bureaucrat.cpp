#include "Bureaucrat.hpp"
#include "AForm.hpp"
using std::string;

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("PNJ"){
	setGrade(75);
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(string src): _name(src){
	setGrade(75);
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(string src, int grade): _name(src){
	try{
		if (grade < 1)
			setGrade(1), throw(GradeTooHighException());
		if (grade > 150)
			setGrade(150), throw(GradeTooLowException());
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
		std::cout << "Bureaucrat has been created" << std::endl;
		return ;
	}
	setGrade(grade);
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name){
	this->_grade = src._grade; 
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat has been destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src){
	this->_grade = src._grade; 
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src){
	os << "\033[1;34m- " <<src.getName() << ", bureaucrat grade " << src.getGrade() << " -\033[0m" <<std::endl;
    return os;
}

string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::setGrade(int src){
	try{
		if (src < 1)
			this->_grade = 1, throw(GradeTooHighException());
		if (src > 150)
			this->_grade = 150, throw(GradeTooLowException());
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
		return ;
	}
	this->_grade = src;
}

void	Bureaucrat::upGrade()
{
	try{
		if (this->_grade - 1 < 1)
			throw(GradeTooHighException());
		std::cout << "\033[1;32m[Upgraded]\033[0m " << getName() << " from grade " << getGrade() << " to " << (getGrade() - 1) << std::endl;
		this->_grade--;
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

void	Bureaucrat::downGrade()
{
	try{
		if (this->_grade + 1 > 150)
			throw(GradeTooLowException());
		std::cout << "\033[1;33m[Downgraded]\033[0m " << getName() << " from grade " << getGrade() << " to " << (getGrade() + 1) << std::endl;
		this->_grade++;
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

void Bureaucrat::signForm(string src, int success) const
{
	if (success == 0)
		std::cout << "\033[1;32m" << this->_name << " signed [" << src << "]" << "\033[0m" << std::endl;
	if (success == 1)
		std::cout << "\033[1;31m /!\\" << this->_name << " couldn't sign [" << src << "]" << " because his grade is too low" << "/!\\\033[0m" << std::endl;
}

void	Bureaucrat::executeForm(const AForm &src){
	src.execute(getGrade(), getName());
}
