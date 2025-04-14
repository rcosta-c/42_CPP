/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:37 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:38 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name),  _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
	if(_weapon)
	{
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " attack with nothing " << std::endl;
	}
}

void    HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
