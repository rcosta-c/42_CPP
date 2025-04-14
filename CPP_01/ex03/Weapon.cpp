/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:46 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:47 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
Weapon::Weapon(std::string type)
{
    this->_type = type;
}
void    Weapon::setType(std::string type)
{
    this->_type = type;
}
std::string const &Weapon::getType(void)
{
    return (this->_type);
}

