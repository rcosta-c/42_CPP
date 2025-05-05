#include "Scalar.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "./convert <value>" << std::endl;
        return 1;
    }
    Scalar::convert(av[1]);
    return 0;
}