#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(Fixed const &src);
		Fixed &operator=(const Fixed&);
		
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		int	number;
		static const int bitNumber = 8;
};

#endif
