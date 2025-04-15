#pragma once

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();
        Fixed &operator=(const Fixed &copy);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int					_value_nbr;
        static const int	_frac_bits = 8;
};