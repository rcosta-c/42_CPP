/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:32:26 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:32:27 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class   Contact
{
	private:
	std::string     _firstname;
	std::string     _lastname;
	std::string     _nickname;
	std::string     _number;
	std::string     _secret;

	public:
	Contact(void);
	~Contact(void);
	/*getters and setters section*/
	std::string     get_firstname(void) const;
	std::string     get_lastname(void) const;
	std::string     get_nickname(void) const;
	std::string     get_number(void) const;
	std::string     get_secret(void) const;
	void            set_firstname(std::string str);
	void            set_lastname(std::string str);
	void            set_nick(std::string str);
	void            set_number(std::string str);
	void            set_secret(std::string str);
};