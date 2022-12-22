#include "Span.hpp"
#include <cstdlib>

Span::Span(unsigned int N): _N(N){
	std::cout << "Constructor called\n";
}

Span::Span(const Span& src): _N(src._N){
	std::cout << "Copy constructor called\n";
}

Span &Span::operator=(const Span& src){
	this->_N = src._N;
	return *this;
}

Span::~Span(){
	std::cout << "Copy constructor called\n";
}

void	Span::addNumber(int nb){
	if (this->_currentN++ == this->_N)
		throw(std::exception());
	this->_numbers.push_back(nb);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	while (begin != end){
		this->_numbers.push_back(*begin);
		std::cout << *begin << std::endl;
		++begin;
	}
	if (this->_currentN++ == this->_N)
		throw(std::exception());
}

int		Span::shortestSpan(){
	std::vector<int> min(this->_N);

	if (this->_currentN <= 1)
		throw(std::exception());
	std::partial_sort_copy(_numbers.begin(), _numbers.end(), min.begin(), min.end());
	int result = 1e9;
	for (unsigned int i = 0; i + 1 < this->_currentN; i++){
		if (min[i + 1] - min[i] < result)
			result = min[i + 1] - min[i];
	}
	if (result <= 0)
		throw(std::exception());
	return (result);
}

int		Span::longestSpan(){
	std::vector<int>::iterator max;
	std::vector<int>::iterator min;

	if (this->_currentN <= 1)
		throw(std::exception());
	max = std::max_element(_numbers.begin(), _numbers.end());
	min = std::min_element(_numbers.begin(), _numbers.end());
	int result = *max - *min;
	if (result <= 0)
		throw(std::exception());
	return (*max - *min);
}
