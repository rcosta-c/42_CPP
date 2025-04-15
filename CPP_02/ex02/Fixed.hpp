#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed &operator=(const Fixed &copy);
		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;
		
		bool    operator>(const Fixed &other) const;
		bool    operator<(const Fixed &other) const;
		bool    operator>=(const Fixed &other) const;
		bool    operator<=(const Fixed &other) const;
		bool    operator==(const Fixed &other) const;
		bool    operator!=(const Fixed &other) const;
		
		Fixed   operator+(const Fixed &other) const;
		Fixed   operator-(const Fixed &other) const;
		Fixed   operator*(const Fixed &other) const;
		Fixed   operator/(const Fixed &other) const;

		Fixed   operator++(int);
		Fixed   operator++();
		Fixed   operator--(int);
		Fixed   operator--();
		
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private:
	int					_value_nbr;
	static const int	_frac_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);