#pragma once
#include <string>
#include <iostream>
using std::string;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat& src);

		int getGrade() const;
		void setGrade(int src);

	private:
		int _grade;
		const string _name;
};