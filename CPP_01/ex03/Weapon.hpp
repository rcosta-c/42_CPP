#pragma once

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string const &getType(void);
	private:
		std::string _type;
};