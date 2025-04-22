/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:37 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/22 11:39:09 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default AAnimal")
{
    std::cout << "AAnimal : Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "AAnimal : Copy constructor called" << std::endl;
    *this = copy;
}

AAnimal::AAnimal(std::string &type) : _type(type)
{
    std::cout << "AAnimal : Constructor with type called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal : Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    std::cout << "AAnimal : Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}
