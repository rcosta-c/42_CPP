/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:10:27 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:10:28 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat : Default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat : Copy constructor called" << std::endl;
    *this = copy;
}

WrongCat::WrongCat(std::string &type) : WrongAnimal(type)
{
    std::cout << "WrongCat : Constructor with type called" << std::endl;
    this->_type = type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat : Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat : Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}