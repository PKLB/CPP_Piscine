#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Span{
	public:
		Span(unsigned int N);
		Span(const Span& src);
		Span &operator=(const Span& src);
		~Span();

		void	addNumber(int nb);
		void	addNumbers(int nb, int nbOfNbs);
		int		shortestSpan();
		int		longestSpan();
	private:
		std::vector<int> 	_numbers;
		unsigned int		_currentN;
		unsigned int 		_N;
};