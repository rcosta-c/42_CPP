/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:27:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/02 23:27:06 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <sstream>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);

        int calculate(const std::string& expression);

    private:
        std::stack<int> _numbers;
        bool isOperator(const char c) const;
        bool isValidToken(const std::string& token) const;
        bool isNumber(const std::string& token) const;
        void performOperation(const char op);
        void clearStack();
};