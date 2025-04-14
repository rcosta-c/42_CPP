/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:40 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
			HumanB(std::string  name);
			~HumanB();
			void	attack();
			void	setWeapon(Weapon &weapon);
			
	private:
			std::string		_name;
			Weapon 			*_weapon;
};