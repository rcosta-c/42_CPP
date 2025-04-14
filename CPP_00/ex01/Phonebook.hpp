/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:32:37 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:32:38 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include "Contacts.hpp"

class Phonebook
{
	private:
		Contact	_contact[8];
		int		_contactcounter;

	public:
		Phonebook(void);
		~Phonebook(void);
	
		void    add_contact();
		void    search_contact();

};