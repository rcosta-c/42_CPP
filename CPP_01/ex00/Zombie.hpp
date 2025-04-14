/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:34:38 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:34:39 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <string>

class   Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		static Zombie* newZombie(std::string name);
	private:
		std::string _name;
};

void randomChump(std::string name);