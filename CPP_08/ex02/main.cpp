/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:55 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 12:24:51 by rcosta-c         ###   ########.fr       */
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

    std::cout << "- Testes Adicionais -" << std::endl << std::endl;
    std::cout << "Teste stack vazia:" << std::endl;
    MutantStack<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    std::cout << "Empty: " << (empty.empty() ? "true" : "false") << std::endl << std::endl;
    
    std::cout << "Teste com strings:" << std::endl;
    MutantStack<std::string> str_stack;
    str_stack.push("hello");
    str_stack.push("world");
    str_stack.push("42");
    std::cout << "Top: " << str_stack.top() << std::endl << std::endl;
    for (MutantStack<std::string>::iterator it = str_stack.begin(); it != str_stack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    std::cout << "Teste cópia:" << std::endl;
    MutantStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);
    MutantStack<int> copy(original);
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    return 0;
}