/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:56:59 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 22:57:00 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "*Class -> A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "*Class -> B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "*Class -> C" << std::endl;
    else
        std::cout << "*Class -> Unknown type" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "&Class -> A" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "&Class -> B" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "&Class -> C" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	std::cout << "&Class -> not identifiable" << std::endl;
}