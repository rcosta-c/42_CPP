#include "includes/easyfind.hpp"

int main(void)
{
    std::vector<int> container;
    int nbr, x, numbers;

    std::cout << "Hello! Find a number in vector!" << std::endl << std::endl;
    std::cout << "How many numbers you want write in Vector?" << std::endl;
    std::cin >> nbr;
    if(nbr < 1)
    {
        std::cout << "It has to be higher then 0" << std::endl;
        return (1);
    }
    std::cout << "Write your numbers" << std::endl;
    x = 0;
    while(x < nbr)
    {
        std::cin >> numbers;
        container.push_back(numbers);
        x++;
    }
    std::cout << "Now, select the number you want to search in container" << std::endl;
    std::cin >> nbr;
    std::cout << "Let's see..." << std::endl << std::endl;
    
    try
    {
        std::cout << *foundeasy(container, nbr) << " was founded in the container!" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}