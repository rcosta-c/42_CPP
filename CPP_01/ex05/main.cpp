#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return (1);
    }
    Harl h;
    h.complain(av[1]);
    return (0);
 
}
// This code is a simple command-line program that takes a single argument (a string representing a level) and uses the Harl class to complain about that level.
// The program first checks if the correct number of arguments is provided (2 arguments: the program name and the level).
// If not, it prints a usage message and returns an error code (1).
// If the correct number of arguments is provided, it creates an instance of the Harl class and calls the complain method with the provided level.
// The Harl class is expected to have a method called complain that takes a string argument and handles the complaint based on the level.   
