#pragma once
#include <iostream>
#include "AForm.hpp"
using std::string;

class AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern& src);

		AForm	*makeForm(string formName, string targetForm);

		class WrongName : public std::exception{
			virtual const char* what() const throw(){
				return("[This form does not exist !]");
			}
		};
};