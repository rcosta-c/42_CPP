/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:09:40 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/23 11:23:17 by rcosta-c         ###   ########.fr       */
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
        virtual void makeSound() const = 0;
        virtual std::string getType() const;
    protected:
        std::string _type;
};