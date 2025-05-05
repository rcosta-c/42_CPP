/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:38:56 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 10:38:57 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
	
		/*getters and setters*/
		std::string	getName();
		int			getGrade();

		/*functions/methods*/
		void		gradeUp();
		void		gradeDown();

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
		std::string const	_name;
		int 				_grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);


