#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
Weapon::Weapon(std::string type)
{
    this->_type = type;
}
void    Weapon::setType(std::string type)
{
    this->_type = type;
}
std::string const &Weapon::getType(void)
{
    return (this->_type);
}

