#include "MyData.hpp"
#include <sstream>
#include <cstdlib> 
using std::string;

int	isDigit(char c)
{
	if (c >= 48 && c <= 57)
		return 1;
	return 0;
}

MyData::MyData(): _MyInt(0), _MyDouble(0.0), _MyFloat(0.0f){
	std::cout << "MyData constructor called !\n";
}

MyData::MyData(string src): _MyInt(0), _MyDouble(0.0), _MyFloat(0.0f){
	std::cout << "MyData constructor called !\n";
	if (src.length() < 1)
		std::cout << "Empty argument.\n";
	setInt(src);
	setFloat(src);
	setChar(src);
	setDouble(src);
}

MyData::~MyData(){
	std::cout << "MyData destructor called !\n";
}

MyData::MyData(const MyData& src){
	std::cout << "MyData copy constructor called !\n";
}		

MyData &MyData::operator=(const MyData& src){
	this->_MyInt = 		src.getInt();
	this->_MyDouble = 	src.getDouble();
	this->_MyFloat = 	src.getFloat();
	this->_MyChar = 	src.getChar();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyData& src){
	os  << "Int: "    << src.getInt() 	 << "\n" 
		<< "Double: " << src.getDouble() << "\n" 
		<< "Float: "  << src.getFloat()  << "\n"
		<< "Char: "	  << src.getChar()   << "\n";
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

void	MyData::setInt(string src){
	std::istringstream stringo(src);
	int result;

	if (src.length() == 1 && isDigit(src[0]) == 0)
	{
		this->_MyInt = (int)src[0];
		std::cout << "Int: " << this->_MyInt << std::endl;
		return ;
	}
	if (src == "nan" | src == "+nan" | src == "-nan"
		| src == "+nanf" | src == "-nanf" | src == "nanf")
	{
		std::cout << "Int: " << "impossible" << std::endl;
		return ;
	}
	stringo >> result;
	this->_MyInt = result;
	std::cout << "Int: " << result << std::endl;
}

void	MyData::setFloat(string src){
	double tempResult;
	float result;
	if (src.length() == 1 && isDigit(src[0]) == 0)
	{
		this->_MyFloat = (float)src[0];
		std::cout << "Float: " << std::showpoint  << this->_MyFloat << "f" << std::endl;
		return ;
	}
	char *tempStr = const_cast<char*>(src.c_str()); // retirer const cast
	try{
		tempResult = std::atof(tempStr);
		result = static_cast<float>(tempResult);
	}
	catch(std::invalid_argument& e){
		std::cout << "Float: " << "impossible" << std::endl;
		return ;
	}
	if (src == "nan" | src == "+nan" | src == "-nan"
		| src == "+nanf" | src == "-nanf" | src == "nanf")
	{
		std::cout << "Float: " << "nanf" << std::endl;
		return ;
	}
	this->_MyFloat = result;
	std::cout << "Float: " << std::showpoint  << result << "f" << std::endl;
}

void	MyData::setDouble(string src){
	double result;
	char *tempStr = const_cast<char*>(src.c_str());// retirer const cast
	if (src.length() == 1 && isDigit(src[0]) == 0)
	{
		this->_MyDouble = (double)src[0];
		std::cout << "Double: " << std::showpoint << std::fixed << std::setprecision(1) << this->_MyDouble << std::endl;
		return ;
	}
	try{
		result = std::atof(tempStr);
	}
	catch(std::invalid_argument& e){
		std::cout << "Float: " << "impossible" << std::endl;
		return ;
	}
	if (src == "nan" | src == "+nan" | src == "-nan"
		| src == "+nanf" | src == "-nanf" | src == "nanf")
	{
		std::cout << "Double: " << "nan" << std::endl;
		return ;
	}
	this->_MyDouble = result;
	std::cout << "Double: " << std::showpoint << std::fixed << std::setprecision(1) << result << std::endl;
}

void	MyData::setChar(string src){
	char result;

	result = getInt();
	if ((src.length() == 1 && src[0] != '0') || (src.length() == 1 && isDigit(src[0]) == 1))
		result = src[0];
	if (src == "nan" | src == "+nan" | src == "-nan"
		| src == "+nanf" | src == "-nanf" | src == "nanf")
	{
		std::cout << "Char: " << "impossible" << std::endl;
		return ;
	}
	else if (result <= 32 | result > 125)
	{
		std::cout << "Char: " << "non displayable" << std::endl;
		return ;
	}
	this->_MyChar = result;
	std::cout << "Char: '" << result << "'\n";
}