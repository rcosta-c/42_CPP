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

bool Fixed::operator>(const Fixed &other) const
{
    return this->_value_nbr > other._value_nbr;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_value_nbr < other._value_nbr;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value_nbr >= other._value_nbr;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value_nbr <= other._value_nbr;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value_nbr == other._value_nbr;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_value_nbr != other._value_nbr;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value_nbr + other._value_nbr);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value_nbr - other._value_nbr);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value_nbr * other._value_nbr) >> _frac_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    if (other._value_nbr != 0)
        result.setRawBits((this->_value_nbr << _frac_bits) / other._value_nbr);
    else
        std::cerr << "Division by zero" << std::endl;
    return result;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++_value_nbr;
    return temp;
}

Fixed Fixed::operator++()
{
    ++_value_nbr;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --_value_nbr;
    return temp;
}

Fixed Fixed::operator--()
{
    --_value_nbr;
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}