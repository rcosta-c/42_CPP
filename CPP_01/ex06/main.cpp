#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./harlFilter [debug/info/warning/error]" << std::endl;
        return (1);
    }
    Harl h;
    h.complain(av[1]);
    return (0);
 
}
