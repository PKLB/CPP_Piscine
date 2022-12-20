#include "Form.hpp"

Form::Form(): _isSigned(0), _execGrade(75), _signGrade(75), _name("Random papers"){
	std::cout << "Form has been created" << std::endl;
}


Form::Form(string src): _isSigned(0), _execGrade(75), _signGrade(75), _name(src){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(const Form &src): _isSigned(src.getSigned()), _execGrade(src._execGrade), _signGrade(src._signGrade), _name(src._name){
	std::cout << "Form has been created" << std::endl;
}

Form::~Form(){
	std::cout << "Form has been destroyed" << std::endl;
}

Form &Form::operator=(const Form&){
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& src){
	if (src.getSigned() == 0)
		os << "\033[1;34m- " << src.getName() << " form isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
	else
		os << "\033[1;34m- " << src.getName() << " form is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
    return os;
}

string Form::getName() const{
	return (this->_name);
}

int Form::getSigned() const{
	return (this->_isSigned);
}

int Form::getExecGrade() const{
	return (this->_execGrade);
}

int Form::getSignGrade() const{
	return (this->_signGrade);
}

void	Form::beSigned(const Bureaucrat& src){
	try{
		if (src.getGrade() > this->_signGrade)
			throw Form::GradeTooLowException();
		this->_isSigned = 1;
		src.signForm(this->_name, 0);
	}
	catch (const std::exception &str){
		src.signForm(this->_name, 1);
		std::cout << str.what() << std::endl;
	}
}
