#include "Data.hpp"

Data::Data(){
	std::cout << "Data constructor called !\n";
}

Data::Data(const Data& src): _intData(src._intData), _stringData(src._stringData) {
	std::cout << "Data copy constructor called !\n";
}

Data::~Data(){
	std::cout << "Data destructor called !\n";
}

Data &Data::operator=(const Data& src){
	this->_intData = src.getIntData();
	this->_stringData = src.getStringData();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& src){
	os << "Int: " << src.getIntData() << "\n" << "String: " << src.getStringData() <<std::endl; 
	return os;
}

int 		Data::getIntData() const{
	return this->_intData;
}

string 		Data::getStringData() const{
	return this->_stringData;
}

uintptr_t 	Data::serialize(Data* ptr){
	uintptr_t test;
	test = reinterpret_cast<uintptr_t>(ptr);
	return (test);
}

Data* 		Data::deserialize(uintptr_t raw){
	Data *test;
	test = reinterpret_cast<Data *>(raw);
	return (test);
}