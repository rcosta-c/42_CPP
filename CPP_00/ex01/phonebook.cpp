#include "phonebook.hpp"

Phonebook::Phonebook() : _contactcounter(0)
{
}

Phonebook::~Phonebook()
{
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void Phonebook::add_contact()
{
    std::string first, last, nick, number, secret;
    std::cout << "First name:" << std::endl;
    std::getline(std::cin, first);
    std::cout << "Last name:" << std::endl;
    std::getline(std::cin, last);
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, nick);
    std::cout << "Phone number:" << std::endl;
    std::getline(std::cin, number);
    std::cout << "Darkest secret:" << std::endl;
    std::getline(std::cin, secret);
    if(first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
    {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    this->_contact[this->_contactcounter % 8].set_firstname(first);
    this->_contact[this->_contactcounter % 8].set_lastname(last);
    this->_contact[this->_contactcounter % 8].set_nick(nick);
    this->_contact[this->_contactcounter % 8].set_number(number);
    this->_contact[this->_contactcounter % 8].set_secret(secret);
    this->_contactcounter++;
}

void Phonebook::search_contact()
{
    int x = 0;
    std::string index;

    if(this->_contactcounter == 0)
    {
        std::cout << "Empty phonebook" << std::endl;
        return;
    }
    std::cout << "Index | First name | Last name | Nickname" << std::endl;
    while(x < _contactcounter)
    {
        std::cout << x << " | ";
        std::cout << std::setw(10) << truncate(this->_contact[x].get_firstname()) << " | ";
        std::cout << std::setw(10) << truncate(this->_contact[x].get_lastname()) << " | ";
        std::cout << std::setw(10) << truncate(this->_contact[x].get_nickname()) << std::endl;
        x++;
    }
    std::cout << "Enter index of contact to view:" << std::endl;
    std::getline(std::cin, index);
    if(index.empty() || index.length() > 1 || index[0] < '0' || index[0] > '7')
    {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    else
    {
        std::cout << "First name: " << this->_contact[index[0] - '0'].get_firstname() << std::endl;
        std::cout << "Last name: " << this->_contact[index[0] - '0'].get_lastname() << std::endl;
        std::cout << "Nickname: " << this->_contact[index[0] - '0'].get_nickname() << std::endl;
        std::cout << "Phone number: " << this->_contact[index[0] - '0'].get_number() << std::endl;
        std::cout << "Darkest secret: " << this->_contact[index[0] - '0'].get_secret() << std::endl;
    }
}