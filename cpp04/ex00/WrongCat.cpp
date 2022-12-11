#include <string>
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->_type = "WrongCat";
	std::cout << "WrongCat constructor called \n";	
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called \n";
}

WrongCat::WrongCat(const WrongCat &src){
		*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat& src){
	std::cout << "Copy assignement operator called\n";
	this->_type = src._type;
	return *this;
}
