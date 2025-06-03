/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:27:09 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/02 23:27:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}
RPN::~RPN()
{}
RPN::RPN(const RPN &copy) : _numbers(copy._numbers)
{}
RPN &RPN::operator=(const RPN &copy)
{
    if(this != &copy)
        *this= copy;
    return(*this);
}

bool RPN::isOperator(const char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isValidToken(const std::string& token) const
{
    if (token.empty())
        return false;
    if (token.length() == 1)
    {
        return (isOperator(token[0]) || (token[0] >= '0' && token[0] <= '9'));
    }
    return false;
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        return true;   
    return false;
}

void RPN::clearStack()
{
    while (!_numbers.empty())
    {
        _numbers.pop();
    }
}

void RPN::performOperation(const char op)
{
    if (_numbers.size() < 2)
    {
        throw std::runtime_error("Error");
    }
    int b = _numbers.top();
    _numbers.pop();
    int a = _numbers.top();
    _numbers.pop();

    long result = 0;
    switch (op)
    {
        case '+':
            result = static_cast<long>(a) + static_cast<long>(b);
            break;
        case '-':
            result = static_cast<long>(a) - static_cast<long>(b);
            break;
        case '*':
            result = static_cast<long>(a) * static_cast<long>(b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error");
            }
            result = static_cast<long>(a) / static_cast<long>(b);
            break;
    }
    
    // check for overflow
    if (result > INT_MAX || result < INT_MIN)
    {
        throw std::runtime_error("Error");
    }
    _numbers.push(static_cast<int>(result));
}

int RPN::calculate(const std::string& expression)
{
    clearStack();
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (!isValidToken(token))
        {
            throw std::runtime_error("Error");
        }
        
        if (isNumber(token))
        {
            int num = token[0] - '0';
            _numbers.push(num);
        }
        else if (token.length() == 1 && isOperator(token[0]))
        {
            performOperation(token[0]);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_numbers.size() != 1)
    {
        throw std::runtime_error("Error");
    }
    return _numbers.top();
}