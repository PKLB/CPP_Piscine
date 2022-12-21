#pragma once
#include <iostream>
#include <string>

template <typename T> 
class Array{
	public:
		Array(){
			this->_elements = new T[0];
			std::cout << "No argument constructor called\n";
		};
		
		Array(const Array &src){
			this->_n = src._n;
			T* temp = new T[src._n];
			for (unsigned int i = 0; i < src._n; i++)
				temp[i] = src._elements[i];
			this->_elements = temp;
			std::cout << "Copy constructor called\n";
		};

		Array(unsigned int n){
			this->_n = n;
			this->_elements = new T[n];
			std::cout << "Unsigned int constructor called\n";
		};

		Array &operator=(const Array& src){
			this->_n = src._n;
			T* temp = new T[src._n];
			for (unsigned int i = 0; i < src._n; i++)
				temp[i] = src.elements[i];
			this->_elements = temp;
			return *this;
		};

		T& operator[](unsigned int index){
			if (index < 0 || index >= this->_n)
				throw IndexOutOfBonds();
			return _elements[index];
		}

		~Array(){
			delete[] this->_elements;
			std::cout << "Destructor called\n";
		};

		unsigned int size() const{
			return (this->_n);
		}
		
		class IndexOutOfBonds : public std::exception{
			virtual const char* what() const throw(){
					return("\033[1;31mexception:[Index out of bonds !]\033[0m\n");
			}
		};

	private:
		T* 				_elements;
		unsigned int	_n;
};
