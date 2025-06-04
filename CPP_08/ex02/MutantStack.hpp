/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:59 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 12:20:50 by rcosta-c         ###   ########.fr       */
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
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        ~MutantStack();
        
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;


        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
