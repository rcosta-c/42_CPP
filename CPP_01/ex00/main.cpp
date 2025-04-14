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