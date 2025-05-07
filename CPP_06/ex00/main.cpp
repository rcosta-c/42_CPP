/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:23:14 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:15 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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