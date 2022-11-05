#include "Bureaucrat.hpp"
#include "Form.hpp"
using std::string;

Bureaucrat::Bureaucrat(): _name("PNJ"){
	std::cout << "Bureaucrat " << this->_name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(string src): _name(src){
	std::cout << "Bureaucrat " << this->_name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(string src, int grade): _name(src){
	setGrade(grade);
	std::cout << "Bureaucrat " << this->_name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name){
	this->_grade = src._grade; 
	std::cout << "Bureaucrat " << this->_name << " has been created" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat has been destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src){
	this->_grade = src._grade; 
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src){
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return os;
}

string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::setGrade(int src){
	if (src > 150)
		this->_grade = 150;
	else if (src < 1)
		this->_grade = 1;
	else
		this->_grade = src;
}

void	Bureaucrat::upGrade(){
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooLowException();
		this->_grade--;
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(){
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooHighException();
		this->_grade++;
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form & src){
	try
	{
		if (getGrade() > src.getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		std::cout << this->_name << " signed " << src.getName() << "\n";
		src.makeItSigned();
	}
	catch (const std::exception &str)
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because " <<  str.what() << "\n";;
	}
}

void	Bureaucrat::executeForm(const Form &src){
	src.execute(getGrade(), getName());
}
