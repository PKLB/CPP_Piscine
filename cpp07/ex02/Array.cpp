#include "Array.hpp"
//template <typename T> class Array;

template <typename T>Array<T>::Array(){
	std::cout << "No argument constructor called\n";
}

template <typename T>Array<T>::Array(const Array<T> &src){
	std::cout << "Copy constructor called\n";
}

template <typename T>Array<T>::Array(unsigned int n){
	std::cout << "Unsigned int constructor called\n";
}

// template <class T>
// MyClass<T>& MyClass<T>::operator+=(const MyClass<T>& classObj)

template <class T>Array<T>& Array<T>::operator=(const Array<T>&Array){

}

template <typename T>Array<T>::~Array(){
	std::cout << "Destructor called\n";
}

template  <typename T>Array<T>::size() const{

}
