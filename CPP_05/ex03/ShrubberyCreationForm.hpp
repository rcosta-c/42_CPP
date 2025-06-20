/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:42:19 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/02 23:42:21 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();

        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;

        static AForm *createShrubberyCreationForm(std::string const &target)
        {
            return new ShrubberyCreationForm(target);
        }

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &form);