#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(Fixed const &);
		Fixed &operator=(const Fixed&);
		
		int getRawBits() const;
		void setRawBits(int value);
	private:
		int	number;
		static const int bitNumber = 8;
};

#endif