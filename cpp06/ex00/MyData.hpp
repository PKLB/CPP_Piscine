#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using std::string;

class	MyData{
	public:
		MyData();
		MyData(char *src);
		MyData(const MyData& src);
		~MyData();
		MyData &operator=(const MyData& src);

		int		getInt() const;
		double	getDouble() const;
		float	getFloat() const;
		char	getChar() const;
		
		void	setInt(string src);
		void	setDouble(char *src);
		void	setFloat(char *src);
		void	setChar(string src);

	private:
		int		_MyInt;
		double	_MyDouble;
		float	_MyFloat;
		char	_MyChar;
};

std::ostream& operator<<(std::ostream& os, const MyData& src);
