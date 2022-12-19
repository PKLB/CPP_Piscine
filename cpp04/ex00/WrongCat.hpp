#pragma once
#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		void makeSound() const;
		WrongCat &operator=(const WrongCat& src);
		~WrongCat();
};