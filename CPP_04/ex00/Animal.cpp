/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:08:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:08:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default")
{
    std::cout << "Animal : Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal : Copy constructor called" << std::endl;
    *this = copy;
}

Animal::Animal(std::string &type) : _type(type)
{
    std::cout << "Animal : Constructor with type called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal : Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal : Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}