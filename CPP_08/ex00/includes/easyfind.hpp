/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:23 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/01 23:30:24 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <exception>
#include <csignal>



class NotInVectorExcep : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return("Not Found in Vector!");
        }

};

template <typename T>
typename T::iterator foundeasy(T &vector, int x)
{
    typename T::iterator it = std::find(vector.begin(), vector.end(), x);
    if(it == vector.end())
        throw NotInVectorExcep();
    return it;
}
