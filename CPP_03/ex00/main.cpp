/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:06:59 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:07:01 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{

	std::cout << std::endl << std::endl;
	std::cout << "Test" << std::endl;
	{
		ClapTrap claptrap("Kim");

		claptrap.attack("Handsome Jack");
		claptrap.takeDamage(5);
		claptrap.beRepaired(3);
		claptrap.displaypoints();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Second Test" << std::endl;
	{
		ClapTrap claptrap("Pam");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.takeDamage(9);
		claptrap.beRepaired(9);
		claptrap.displaypoints();
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Third Test" << std::endl;
	{
		ClapTrap claptrap("Ze-ro");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.beRepaired(10);
		claptrap.displaypoints();
		claptrap.attack("Handsome Jack");
		claptrap.displaypoints();
	}
	std::cout << std::endl << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Fourth Test" << std::endl;
	{
		ClapTrap claptrap;
		claptrap.displaypoints();
	}
	std::cout << std::endl << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Fifth Test - Copy Constructor" << std::endl;
	{
		ClapTrap original("Original");
		original.displaypoints();
		
		// Make some changes to demonstrate the copy
		original.attack("Enemy");
		original.takeDamage(3);
		std::cout << "Original after changes:" << std::endl;
		original.displaypoints();
		
		// Use the copy constructor
		ClapTrap copy(original);
		std::cout << "Copy status:" << std::endl;
		copy.displaypoints();
		
		// Modify only the original to demonstrate independence
		original.takeDamage(4);
		original.beRepaired(1);
		
		std::cout << "After modifying only the original:" << std::endl;
		std::cout << "Original: ";
		original.displaypoints();
		std::cout << "Copy: ";
		copy.displaypoints();
	}
	std::cout << std::endl << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Sixth Test - Assignment Operator" << std::endl;
	{
		ClapTrap first("First");
		ClapTrap second("Second");
		
		// Modify the first ClapTrap
		first.attack("Enemy");
		first.takeDamage(5);
		first.beRepaired(2);
		
		std::cout << "Before assignment:" << std::endl;
		std::cout << "First: ";
		first.displaypoints();
		std::cout << "Second: ";
		second.displaypoints();
		
		// Use the assignment operator
		second = first;
		
		std::cout << "After assignment (second = first):" << std::endl;
		std::cout << "First: ";
		first.displaypoints();
		std::cout << "Second: ";
		second.displaypoints();
		
		// Modify only the first to demonstrate independence
		first.beRepaired(3);
		first.attack("Another enemy");
		
		std::cout << "After modifying only the first:" << std::endl;
		std::cout << "First: ";
		first.displaypoints();
		std::cout << "Second: ";
		second.displaypoints();
	}
	return 0;
}

