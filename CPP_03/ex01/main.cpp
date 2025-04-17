/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:07:15 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:07:16 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap Tests (from ex00)
    std::cout << std::endl << std::endl;
    std::cout << "ClapTrap Test" << std::endl;
    {
        ClapTrap claptrap("Kim");

        claptrap.attack("Handsome Jack");
        claptrap.takeDamage(5);
        claptrap.beRepaired(3);
        claptrap.displaypoints();
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Second ClapTrap Test" << std::endl;
    {
        ClapTrap claptrap("Pam");
        claptrap.displaypoints();
        claptrap.attack("Handsome Jack");
        claptrap.takeDamage(9);
        claptrap.beRepaired(9);
        claptrap.displaypoints();
    }

    // ScavTrap Tests (new for ex01)
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Basic Test" << std::endl;
    {
        ScavTrap scavtrap("Guardian");
        scavtrap.displaypoints();
        scavtrap.attack("Hyperion Robot");
        scavtrap.takeDamage(20);
        scavtrap.beRepaired(15);
        scavtrap.guardGate();
        scavtrap.displaypoints();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Energy Test" << std::endl;
    {
        ScavTrap scavtrap("Sentinel");
        scavtrap.displaypoints();
        
        // Test multiple attacks to deplete energy points
        for (int i = 0; i < 5; i++) {
            std::cout << "Attack " << i+1 << ":" << std::endl;
            scavtrap.attack("Enemy Bot");
            scavtrap.displaypoints();
        }
        
        // Try to repair after attacks
        scavtrap.beRepaired(10);
        scavtrap.displaypoints();
        
        // Try guardGate with low energy
        scavtrap.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Damage Test" << std::endl;
    {
        ScavTrap scavtrap("Protector");
        scavtrap.displaypoints();
        
        // Test high damage
        scavtrap.takeDamage(80);
        scavtrap.displaypoints();
        
        // Try actions after high damage
        scavtrap.attack("Enemy");
        scavtrap.beRepaired(30);
        scavtrap.guardGate();
        
        // Final blow
        scavtrap.takeDamage(50);
        scavtrap.displaypoints();
        
        // Try actions after destruction
        scavtrap.attack("Enemy");
        scavtrap.beRepaired(100);
        scavtrap.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Copy Constructor Test" << std::endl;
    {
        ScavTrap original("Original");
        original.displaypoints();
        
        // Make some changes
        original.attack("Enemy");
        original.takeDamage(30);
        std::cout << "Original after changes:" << std::endl;
        original.displaypoints();
        
        // Use copy constructor
        ScavTrap copy(original);
        std::cout << "Copy status:" << std::endl;
        copy.displaypoints();
        
        // Modify only the original
        original.takeDamage(20);
        original.beRepaired(10);
        
        std::cout << "After modifying only the original:" << std::endl;
        std::cout << "Original: ";
        original.displaypoints();
        std::cout << "Copy: ";
        copy.displaypoints();
        
        // Test specific ScavTrap function on both
        original.guardGate();
        copy.guardGate();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "ScavTrap Assignment Operator Test" << std::endl;
    {
        ScavTrap first("First");
        ScavTrap second("Second");
        
        // Modify the first ScavTrap
        first.attack("Enemy");
        first.takeDamage(25);
        first.beRepaired(10);
        first.guardGate();
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "First: ";
        first.displaypoints();
        std::cout << "Second: ";
        second.displaypoints();
        
        // Use assignment operator
        second = first;
        
        std::cout << "After assignment (second = first):" << std::endl;
        std::cout << "First: ";
        first.displaypoints();
        std::cout << "Second: ";
        second.displaypoints();
        
        // Modify only the first
        first.beRepaired(15);
        first.attack("Another enemy");
        
        std::cout << "After modifying only the first:" << std::endl;
        std::cout << "First: ";
        first.displaypoints();
        std::cout << "Second: ";
        second.displaypoints();
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Inheritance Demonstration Test" << std::endl;
    {
        std::cout << "Creating a ClapTrap:" << std::endl;
        ClapTrap claptrap("Basic");
        claptrap.displaypoints();
        
        std::cout << "\nCreating a ScavTrap:" << std::endl;
        ScavTrap scavtrap("Advanced");
        scavtrap.displaypoints();
        
        // Show that both can perform base class actions
        std::cout << "\nBoth can attack:" << std::endl;
        claptrap.attack("Target1");
        scavtrap.attack("Target2");
        
        // Show unique ScavTrap ability
        std::cout << "\nOnly ScavTrap has guardGate:" << std::endl;
        scavtrap.guardGate();
    }

    return 0;
}