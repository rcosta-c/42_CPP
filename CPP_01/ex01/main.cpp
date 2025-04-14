#include "Zombie.hpp"

int main(void)
{
    std::string zombieName;
    int numberofzombies = 0;
    bool validInput = false;



    while (validInput == false)
    {
        std::cout << "How many zombies do you want to create: (from 0 to 250)";
        std::cin >> numberofzombies;
        if(numberofzombies <= 0 || numberofzombies > 250)
        {
            std::cout << "Invalid quantity. Please enter a number between 1 and 250." << std::endl;
        }
        else
        {
            validInput = true;
        }
    }
    std::cout << "Name your Zombie: ";
    std::cin >> zombieName;
    Zombie *Horde = zombieHorde(numberofzombies, zombieName);
    if (!Horde)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (1);
    }
    for (int i = 0; i < numberofzombies; i++)
    {
        Horde[i].announce();
    }
    delete[] Horde;
    return (0);    
}