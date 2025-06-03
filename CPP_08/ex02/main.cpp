/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:55 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/02 23:27:59 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
  	std::cout << "Hello! Tester from subject!" << std::endl;

    MutantStack<int> mstack; //LIFO (Last In, First Out)
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  //show what element is on top.doesnt remove it
    mstack.pop(); //it removes the element on the top.doesnt show it.
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}