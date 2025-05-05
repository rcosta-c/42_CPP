/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:39:00 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 10:39:01 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    this->_grade = grade;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat: Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        _grade = copy._grade;
        std::cout << "Bureaucrat: Assignment operator called" << std::endl;
    }
    return *this;
}

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::gradeUp()
{
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::gradeDown()
{
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
