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
		
		int 	getRawBits(void);
		void 	setRawBits(int const raw);

		float 	toFloat (void) const;
		int		toInt (void) const;
	private:
		int	_number;
		static const int _bitNumber = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif