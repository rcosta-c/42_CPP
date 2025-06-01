/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:59 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/01 23:31:00 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : stack()
        {}

        MutantStack(const MutantStack &copy) : stack(copy)
        {}
        
        MutantStack &operator=(const MutantStack &copy)
        {
            if(this != &copy)
				*this= copy;
			return(*this);
        }
        
        ~MutantStack()
        {}
        
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;

        iterator begin()
        {
            return(stack::c.begin());
        }
        iterator end()
        {
            return(stack::c.end());
        }
};