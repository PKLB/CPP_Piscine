#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		void makeSound() const;
};