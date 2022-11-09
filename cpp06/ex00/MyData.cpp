#include "MyData.hpp"
using std::string;

MyData::MyData(){
	std::cout << "MyData constructor called !\n";
}

MyData::MyData(string src){
	std::cout << "MyData constructor called !\n";
}

MyData::~MyData(){
	std::cout << "MyData destructor called !\n";
}

MyData::MyData(const MyData& src){
	std::cout << "MyData copy constructor called !\n";
}		


MyData &MyData::operator=(const MyData& src){
	this->_MyInt = src.getInt();
	this->_MyDouble = src.getDouble();
	this->_MyFloat = src.getFloat();
	this->_MyChar = src.getChar();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyData& src){
	os << "Int: " << src.getInt() << "\n" 
		<< "Double: "<< src.getDouble() << "\n" 
		<< "Float: "	<< src.getFloat() << "\n"
			<< "Char: "	<< src.getChar() << "\n";
    return os;
}

int		MyData::getInt() const{
	return (this->_MyInt);
}

double	MyData::getDouble() const{
	return (this->_MyDouble);
}

float	MyData::getFloat() const{
	return (this->_MyFloat);
}

char	MyData::getChar() const{
	return (this->_MyChar);
}
