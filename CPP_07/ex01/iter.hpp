/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:26 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:27 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

template <typename T>

void    iter(T *array, size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; ++i)
    {
        f(array[i]);
    }
}