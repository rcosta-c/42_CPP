/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:10:08 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/18 00:10:09 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        Dog(const Dog &copy);
        Dog(std::string &type);
        virtual ~Dog();
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};