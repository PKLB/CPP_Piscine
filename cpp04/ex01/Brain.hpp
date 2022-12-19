#pragma once
#include <string>
#include <iostream>

using std::string;

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		virtual ~Brain();
		
		string printIdeas(int i) const;
		void	changeIdeas();
		Brain &operator=(const Brain& src);
	private:
		std::string _Ideas[100];
};