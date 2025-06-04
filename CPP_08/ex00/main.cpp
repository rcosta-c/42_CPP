/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:14 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/01 23:30:16 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/easyfind.hpp"

void signal_handler(int signal)
{
    if (signal == SIGINT)
    {
        std::cout << std::endl << "Bye!!!" << std::endl;
        exit(1);
    }
}

int main(void)
{
    std::vector<int> container;
    int nbr, x, numbers;
    std::signal(SIGINT, signal_handler);

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