/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:32:29 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:32:30 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook 	phonebook;
	std::string	cmdline;

	std::cout << "Welcome to Phonebook" << std::endl;
	while(1)
	{
		std::cout << "Options: ADD, SEARCH, EXIT" << std::endl;
		if(!std::getline(std::cin, cmdline))
		{
			break;
		}
		if(cmdline == "ADD" || cmdline == "add")
		{
			phonebook.add_contact();
		}
		else if(cmdline == "SEARCH" || cmdline == "search")
		{
			phonebook.search_contact();
		}
		else if(cmdline == "EXIT" || cmdline == "exit")
			break;
		else
		{
			std::cout << "Invalid Option." << std::endl;
			std::cout << "Available options: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return (0);
}