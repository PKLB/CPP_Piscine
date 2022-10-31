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

		string *getIdeas() const;
		void setIdeas(string src);
				
		Brain &operator=(const Brain& src);
		friend std::ostream& operator<<(std::ostream& os, const Brain& src);

	protected:
		std::string *_Ideas;
};