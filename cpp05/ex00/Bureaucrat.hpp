#pragma once
#include <string>
#include <iostream>
#include <exception>
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
		void	upGrade();
		void	downGrade();

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw(){
				return("Grade too high !");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw(){
				return("Grade too low !");
			}
		};

	private:
		int _grade;
		const string _name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);
