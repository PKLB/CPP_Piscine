#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const int);
		Fixed(Fixed const &);
		Fixed(const float nb);
		Fixed &operator=(const Fixed&);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& src);
		
		float toFloat (void);
		int	toInt (void) const;
	private:
		int	number;
		static const int bitNumber = 8;
};

#endif