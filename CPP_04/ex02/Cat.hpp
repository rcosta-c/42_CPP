/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:10:01 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/23 11:18:05 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat(const Cat &copy);
        Cat(std::string &type);
        virtual ~Cat();
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};