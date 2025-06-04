/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:39 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 12:30:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

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
	std::signal(SIGINT, signal_handler);
	std::cout << "Hello! Find the shortspan and longspan in a vector!" << std::endl;
	std::cout << "numbers = 1, 3, 9, 11, 19" << std::endl;
	Span sp1 = Span(5);
	sp1.addnbr(1);
	sp1.addnbr(3);
	sp1.addnbr(11);
	sp1.addnbr(9);
	sp1.addnbr(19);
	std::cout << "Shortest Span is: " << sp1.shrtspan() << std::endl;
	std::cout << "Longest Span is:" << sp1.lngspan() << std::endl << std::endl;




	
	std::cout << "Hello! Find the shortspan and longspan in a vector!" << std::endl;
	std::cout << "How many numbers? (randomly selected)" << std::endl;
	unsigned int maxnumbers;
	unsigned int z;
	std::cin >> z;
	std::cout << "Whats the bigger random number that can generate?" << std::endl;
	std::cin >> maxnumbers;

	Span sp = Span(z);
	srand(time(0));
	std::cout << "Selecting numbers..." << std::endl;
	for(unsigned int zz = 0; zz < z;zz++)
	{
		int n = rand() % maxnumbers;
		std::cout << n << std::endl;
		sp.addnbr(n);
	}
	std::cout << std::endl << "RESULTS:" << std::endl;
	std::cout << "Shortest Span is: " << sp.shrtspan() << std::endl;
	std::cout << "Longest Span is:" << sp.lngspan() << std::endl;
		

}