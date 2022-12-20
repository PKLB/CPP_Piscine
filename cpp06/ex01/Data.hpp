#pragma once
#include <iostream>
#include <string>
using std::string;

class	Data{
	public:
		Data();
		Data(const Data& src);
		~Data();
		Data &operator=(const Data& src);

		uintptr_t 	serialize(Data* ptr);
		Data* 		deserialize(uintptr_t raw);

		int 		getIntData() const;
		string 		getStringData() const;

	private:
		int 	_intData;
		string _stringData;

};

std::ostream& operator<<(std::ostream& os, const Data& src);