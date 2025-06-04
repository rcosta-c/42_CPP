/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:30:45 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/04 13:08:24 by rcosta-c         ###   ########.fr       */
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

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		addnbr(*it);
	}
}

void Span::testWithRandomNumbers()
{
    std::cout << "Hello! Find the shortspan and longspan in a vector!" << std::endl;
    std::cout << "How many numbers? (randomly selected)" << std::endl;
    unsigned int maxnumbers;
    unsigned int z;
    std::cin >> z;
    std::cout << "Whats the bigger random number that can generate?" << std::endl;
    std::cin >> maxnumbers;

    Span sp = Span(z);
    
    // Criar um vector com números aleatórios
    std::vector<int> randomNumbers;
    srand(time(0));
    std::cout << "Selecting numbers..." << std::endl;
    for(unsigned int zz = 0; zz < z; zz++) {
        int n = rand() % maxnumbers;
        std::cout << n << std::endl;
        randomNumbers.push_back(n);
    }
    
    // Usar o novo método addNumbers com iteradores
    sp.addNumbers(randomNumbers.begin(), randomNumbers.end());
    
    std::cout << std::endl << "RESULTS:" << std::endl;
    std::cout << "Shortest Span is: " << sp.shrtspan() << std::endl;
    std::cout << "Longest Span is:" << sp.lngspan() << std::endl;
}