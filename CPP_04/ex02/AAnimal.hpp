/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:40 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:09:41 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);
        AAnimal(std::string &type);
        virtual ~AAnimal();
        AAnimal &operator=(const AAnimal &copy);
        virtual void makeSound() const;
        virtual std::string getType() const;
    protected:
        std::string _type;
};