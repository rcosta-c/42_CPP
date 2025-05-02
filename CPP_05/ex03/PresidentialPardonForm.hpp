/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:42:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/02 23:42:06 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm();

        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;

        static AForm *createPresidentialPardonForm(std::string const &target)
        {
            return new PresidentialPardonForm(target);
        }

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form);