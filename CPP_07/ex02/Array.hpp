/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:12 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:14 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>


template <typename T>


class Array
{
    public:
        Array() : _array(0), _lenght(0){}

        Array(unsigned int n) : _array(new T[n]()), _lenght(n) {}
        
        Array(const Array &src) : _array(new T[src._lenght]), _lenght(src._lenght)
        {
            for (unsigned int i = 0; i < _lenght; ++i)
                _array[i] = src._array[i];
        }
        
        Array &operator=(const Array &src)
        {
            if (this != &src)
            {
                delete[] _array;
                _lenght = src._lenght;
                _array = new T[_lenght];
                for (unsigned int i = 0; i < _lenght; ++i)
                    _array[i] = src._array[i];
            }
            return *this;
        }

        ~Array()
        {
            delete[] _array;
        }

        unsigned int size() const
        {
            return this->_lenght;
        }

        T &operator[](unsigned int index)
        {
            if (index >= _lenght)
                throw std::exception();
            return _array[index];
        };

    private:
        T *_array;
        unsigned int _lenght;
};