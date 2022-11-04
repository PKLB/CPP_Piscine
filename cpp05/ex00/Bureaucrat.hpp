#pragma once
#include <string>
#include <iostream>
using std::string;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(string src);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat& src);

		int getGrade() const;
		string getName() const;
		void setGrade(int src);

	private:
		int _grade;
		const string _name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);
