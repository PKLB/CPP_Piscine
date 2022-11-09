#pragma once
#include <iostream>
#include <string>
using std::string;

class	MyData{
	public:
		MyData();
		MyData(string src);
		MyData(const MyData& src);
		~MyData();
		MyData &operator=(const MyData& src);

		int		getInt() const;
		double	getDouble() const;
		float	getFloat() const;
		char	getChar() const;
		
		void	setInt(string src);
		void	setDouble(string src);
		void	setFloat(string src);
		void	setChar(string src);

	private:
		int		_MyInt;
		double	_MyDouble;
		float	_MyFloat;
		char	_MyChar;
};

std::ostream& operator<<(std::ostream& os, const MyData& src);
