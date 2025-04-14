/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:57 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:58 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
    std::string str = "HI THIS IS BRAIN"; // Original string declaration
	std::string *stringPTR = &str; // Pointer to the string
	std::string &stringREF = str; // Reference to the string

    std::cout << "memory address of the string variable: " << &str << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF.: " << &stringREF << std::endl;

    std::cout << "value of the string variable: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}