/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:08:27 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:08:28 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog : Default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog : Copy constructor called" << std::endl;
    *this = copy;
}

Dog::Dog(std::string &type) : Animal(type)
{
    std::cout << "Dog : Constructor with type called" << std::endl;
    this->_type = type;
}

Dog::~Dog()
{
    std::cout << "Dog : Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog : Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}