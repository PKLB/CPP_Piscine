#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int	main ()
{
	Animal *tab[4];
	for (int i = 0; i < 2; i++)
		tab[i] = new Dog();
	for (int i = 2; i < 4; i++)
		tab[i] = new Cat();
	tab[1]->makeSound();
	tab[3]->makeSound();
	std::cout << tab[3]->getBrain()->printIdeas(50) << std::endl;
	tab[3]->getBrain()->changeIdeas();
	std::cout << tab[3]->getBrain()->printIdeas(50) << std::endl;
	for (int i = 0; i < 4; i++)
		delete tab[i];
	return (0);
}