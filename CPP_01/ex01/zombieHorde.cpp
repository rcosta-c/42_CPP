/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:34:02 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:34:03 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    if (!horde)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}