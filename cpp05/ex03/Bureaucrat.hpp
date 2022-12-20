#pragma once
#include <iostream>
#include "AForm.hpp"
using std::string;

class Form;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(string name);
		Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat& src);

		int 	getGrade() const;
		string 	getName() const;
		void 	setGrade(int src);
		void	signForm(AForm& src);
		void	upGrade();
		void	downGrade();
		void	signForm(string src, int success) const;
		void	executeForm(AForm const &src);

		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw(){
				return("Grade too high !");
			}
		};
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw(){
				return("Grade too low !");
			}
		};
	
	private:
		int _grade;
		const string _name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);
