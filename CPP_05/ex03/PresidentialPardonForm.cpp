/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:42:01 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/02 23:42:02 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 145, 137), _target("Default")
{
    std::cout << "Presidential: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target)
{
    std::cout << "Presidential: Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Presidential: opy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Presidential: Assignment operator called" << std::endl;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential: Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form)
{
    out << "PresidentialPardonForm: " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
    return out;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::beExecuted(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
