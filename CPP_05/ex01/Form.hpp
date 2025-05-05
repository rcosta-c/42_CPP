/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:40:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 10:40:32 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form &form);