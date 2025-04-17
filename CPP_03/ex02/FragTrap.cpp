/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:07:35 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:07:36 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on!" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor with name called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    std::cout << "FragTrap " << this->_name << " is on!" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is off!" << std::endl;
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " : high five!" << std::endl;
}

