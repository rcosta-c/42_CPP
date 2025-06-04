/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:36 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 13:09:08 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>
#include <csignal>

class Span
{
    public:
        Span(unsigned int x);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        void addnbr(int x);
        int shrtspan();
        int lngspan();
        static void testWithRandomNumbers();
       
        template<typename Iterator>
        void addNumbers(Iterator begin, Iterator end);

    private:
        unsigned int   _nbrLimit;
        std::vector<int> _numbers;
};

