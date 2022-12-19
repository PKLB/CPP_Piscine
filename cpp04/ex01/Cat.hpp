#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();

		Cat &operator=(const Cat& src);
		Brain *getBrain() const;

		void makeSound() const;
	private:
		Brain *_Brain;
};