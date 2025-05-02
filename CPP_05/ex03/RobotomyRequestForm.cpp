/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:42:08 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/02 23:42:09 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default", 145, 137), _target("Default")
{
    std::cout << "Robotomy: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137), _target(target)
{
    std::cout << "Robotomy: Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Robotomy: Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Robotomy: Assignment operator called" << std::endl;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy: Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &form)
{
    out << "RobotomyRequestForm: " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
    return out;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));
	int randNum = rand() % 2;
	AForm::beExecuted(executor);
	std::cout << "robot sounds " << std::endl;
	if (randNum)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}