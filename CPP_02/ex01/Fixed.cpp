#include "Fixed.hpp"

Fixed::Fixed() : _value_nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const value) : _value_nbr(value << _frac_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value_nbr(roundf(value * (1 << _frac_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_value_nbr = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value_nbr;
}

void Fixed::setRawBits(int const value)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value_nbr = value;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value_nbr / (1 << _frac_bits);
}

int Fixed::toInt(void) const
{
    return this->_value_nbr >> _frac_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}