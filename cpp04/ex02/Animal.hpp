#pragma once
#include <string>
#include <iostream>
#include "Brain.hpp"
using std::string;

class Animal
{
	public:
		Animal();
		Animal(string src);
		Animal(const Animal &src);
		virtual ~Animal();

		string getType() const;
		void setType(string src);
		virtual Brain *getBrain() const;
				
		Animal &operator=(const Animal& src);

		virtual void makeSound() const = 0;
	protected:
		string _type;
};