#include <string>
#include <iostream>
#include "Cat.hpp"

Cat::Cat(){
	this->_type = "Cat";
	std::cout << "Cat constructor called \n";	
}
                            
Cat::~Cat(){
	std::cout << "Cat destructor called \n";
}

Cat::Cat(const Cat &src){
	*this = src;
}

Cat &Cat::operator=(const Cat& src){
	std::cout << "Copy assignement operator called\n";
	this->_type = src._type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "miou miou je suis le chat\n";
}