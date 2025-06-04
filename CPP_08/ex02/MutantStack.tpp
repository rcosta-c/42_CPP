/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:25:36 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 12:25:37 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
    if(this != &copy)
        std::stack<T>::operator=(copy);
    return(*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>        
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}