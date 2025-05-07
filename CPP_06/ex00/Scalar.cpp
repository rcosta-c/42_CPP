/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:23:09 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{
}

Scalar::Scalar(const Scalar &src)
{
    (void)src;
}

Scalar &Scalar::operator=(const Scalar &src)
{
    (void)src;
    return *this;
}

Scalar::~Scalar()
{
}

void Scalar::convert(const std::string &value)
{
    if (value.empty())
    {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    ScalarType type = identifyType(value);
    
    switch (type)
    {
        case CHAR:
            convertFromChar(value[0]);
            break;
        case INT:
            convertFromInt(std::atoi(value.c_str()));
            break;
        case FLOAT:
            convertFromFloat(std::atof(value.c_str()));
            break;
        case DOUBLE:
            convertFromDouble(std::atof(value.c_str()));
            break;
        case PSEUDO:
            handlePseudo(value);
            break;
        case INVALID:
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: Impossible" << std::endl;
            std::cout << "double: Impossible" << std::endl;
            break;
    }
}

ScalarType Scalar::identifyType(const std::string &value)
{
    if (isPseudo(value))
        return PSEUDO;
    if (isChar(value))
        return CHAR;
    if (isInt(value))
        return INT;
    if (isFloat(value))
        return FLOAT;
    if (isDouble(value))
        return DOUBLE;
    return INVALID;
}

bool Scalar::isChar(const std::string &value)
{
    return (value.length() == 1 && !std::isdigit(value[0]));
}

bool Scalar::isInt(const std::string &value)
{
    size_t i = 0;
    if (value[i] == '+' || value[i] == '-')
        i++;
    while (i < value.length())
    {
        if (!std::isdigit(value[i]))
            return false;
        i++;
    }
    return true;
}

bool Scalar::isFloat(const std::string &value)
{
    if (value[value.length() - 1] != 'f')
        return false;
    
    std::string temp = value.substr(0, value.length() - 1);
    size_t i = 0;
    bool decimal = false;
    
    if (temp[i] == '+' || temp[i] == '-')
        i++;
        
    while (i < temp.length())
    {
        if (temp[i] == '.')
        {
            if (decimal)
                return false;
            decimal = true;
        }
        else if (!std::isdigit(temp[i]))
            return false;
        i++;
    }
    return decimal;
}

bool Scalar::isDouble(const std::string &value)
{
    size_t i = 0;
    bool decimal = false;
    
    if (value[i] == '+' || value[i] == '-')
        i++;
      
    while (i < value.length())
    {
        if (value[i] == '.')
        {
            if (decimal)
                return false;
            decimal = true;
        }
        else if (!std::isdigit(value[i]))
        {
            return false;
        }
        i++;
    }
    return decimal;
}

bool Scalar::isPseudo(const std::string &value)
{
    return (value == "nan" || value == "+inf" || value == "-inf" || 
            value == "nanf" || value == "+inff" || value == "-inff" ||
            value == "inf" || value == "inff");
}

void Scalar::convertFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void Scalar::convertFromInt(int n)
{
    // Char
    if (n >= 32 && n <= 126)
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else if (n >= 0 && n <= 127)
        std::cout << "char: não imprimível" << std::endl;
    else
        std::cout << "char: Impoosibel" << std::endl;
    
    // Int
    std::cout << "int: " << n << std::endl;
    
    // Float
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    
    // Double
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void Scalar::convertFromFloat(float f)
{
    // Char
    if (f >= 32 && f <= 126 && f == static_cast<int>(f))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else if (f >= 0 && f <= 127 && f == static_cast<int>(f))
        std::cout << "char: não imprimível" << std::endl;
    else
        std::cout << "char: Impoosibel" << std::endl;
    
    // Int
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() && !std::isnan(f))
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: Impoosibel" << std::endl;
    
    // Float
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    // Double
    if (f == static_cast<int>(f))
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

// Conversão a partir de double
void Scalar::convertFromDouble(double d)
{
    // Char
    if (d >= 32 && d <= 126 && d == static_cast<int>(d))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= 0 && d <= 127 && d == static_cast<int>(d))
        std::cout << "char: não imprimível" << std::endl;
    else
        std::cout << "char: Impoosibel" << std::endl;
    
    // Int
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() && !std::isnan(d))
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: Impoosibel" << std::endl;
    
    // Float
    if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
    {
        if (d == static_cast<int>(d))
            std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    }
    else
        std::cout << "float: Impoosibel" << std::endl;
    
    // Double
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

// Lidar com valores pseudo literais
void Scalar::handlePseudo(const std::string &value)
{
    std::cout << "char: Impoosibel" << std::endl;
    std::cout << "int: Impoosibel" << std::endl;
    
    if (value == "nan" || value == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (value == "+inf" || value == "+inff" || value == "inf" || value == "inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (value == "-inf" || value == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
