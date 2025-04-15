#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();
        Fixed &operator=(const Fixed &copy);
        int getRawBits(void) const;
        void setRawBits(int const value);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int					_value_nbr;
        static const int	_frac_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
