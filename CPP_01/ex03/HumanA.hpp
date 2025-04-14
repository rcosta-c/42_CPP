/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:35 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:37 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA();
			void	attack();
	private:
			std::string 	_name;
			Weapon 			&_weapon;
};