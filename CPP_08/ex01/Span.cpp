/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:45 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/01 23:30:46 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

Span::Span(unsigned int x) : _nbrLimit(x)
{}

Span::~Span()
{}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_nbrLimit = copy._nbrLimit;
		_numbers = copy._numbers;
	}
	return (*this);
}

void Span::addnbr(int x)
{
	if (_numbers.size() >= _nbrLimit)
	{
		throw std::runtime_error("Span is full");
	}
	_numbers.push_back(x);
}

int Span::shrtspan()
{
	if (_numbers.size() < 2)
	{
		throw std::runtime_error("Need at least 2 numbers");
	}
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i-1];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::lngspan()
{
	if (_numbers.size() < 2)
	{
        throw std::runtime_error("Need at least 2 numbers");
    }
    std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}