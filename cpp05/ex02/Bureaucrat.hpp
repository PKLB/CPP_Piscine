#pragma once
#include <string>
#include <iostream>
using std::string;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(string src);
		Bureaucrat(string src, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat& src);

		int 	getGrade() const;
		string 	getName() const;
		void 	setGrade(int src);
		string	signForm(string src, int success) const;
		void	upGrade();
		void	downGrade();

		string	GradeTooHighException() const;
		string	GradeTooLowException() const;
		string	ExecTooLowException() const;

	
	private:
		int _grade;
		const string _name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);
