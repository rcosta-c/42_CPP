/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:08:14 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:08:15 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal(std::string type);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &copy);
        void makeSound() const;
        std::string getType() const;

    protected:
        std::string _type;
};