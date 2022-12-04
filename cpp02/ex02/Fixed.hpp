#pragma once
#include <iostream>
#include <string>

class	Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const int);
		Fixed(Fixed const &);
		Fixed(const float nb);

		Fixed &operator=(const Fixed&);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		Fixed &operator+=(const Fixed&src);
		Fixed operator+(const Fixed&src);
		Fixed &operator-=(const Fixed&src);
		Fixed operator-(const Fixed&src);
		Fixed &operator*=(const Fixed&src);
		Fixed operator*(const Fixed&src);
		Fixed &operator/=(const Fixed&src);
		Fixed operator/(const Fixed&src);
		bool operator<(const Fixed&src);
		bool operator>(const Fixed&src);
		bool operator<=(const Fixed&src);
		bool operator>=(const Fixed&src);
		bool operator!=(const Fixed&src);
		bool operator==(const Fixed&src);

		Fixed &min(const Fixed&src, const Fixed&src2);
		Fixed &max(const Fixed&src, const Fixed&src2);
		
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

		float 	toFloat (void) const;
		int		toInt (void) const;
	private:
		int	_number;
		static const int _bitNumber = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& src);
