/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/19 23:56:28 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat : Default constructor called" << std::endl;
    _brain = new Brain();
    this->_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat : Copy constructor called" << std::endl;
    _brain = new Brain();
    *this = copy;
}

Cat::Cat(std::string &type) : Animal(type)
{
    std::cout << "Cat : Constructor with type called" << std::endl;
    _brain = new Brain();
    this->_type = type;
}

Cat::~Cat()
{
    std::cout << "Cat : Destructor called" << std::endl;
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat : Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->_brain;
}