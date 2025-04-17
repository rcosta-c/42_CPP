/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:46 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:09:47 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(const Animal &copy);
        Animal(std::string &type);
        virtual ~Animal();
        Animal &operator=(const Animal &copy);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;
};