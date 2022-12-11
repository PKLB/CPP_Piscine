#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &);
		~Dog();
		Dog &operator=(const Dog& src);

		void makeSound() const;
};