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