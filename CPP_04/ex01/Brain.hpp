/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:01 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:09:02 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
    private:
		std::string ideas[100];
};