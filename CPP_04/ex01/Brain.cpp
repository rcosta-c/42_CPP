/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:08:58 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:08:59 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain : Copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain : Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}
