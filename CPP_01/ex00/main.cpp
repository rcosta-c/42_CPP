/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:34:21 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:34:22 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	std::string	Zombiename;

	std::cout << "What's Zombie name: ";
	std::getline(std::cin, Zombiename);
	zombie = new Zombie(Zombiename);
	if(!zombie)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return (1);
	}
	zombie->announce();
	delete zombie;
	randomChump(Zombiename);
	return (0);
}