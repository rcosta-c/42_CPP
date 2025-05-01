#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		/*getters and setters*/
		std::string	getName() const;
		int			getGrade() const;

		/*functions/methods*/
		void		gradeUp();
		void		gradeDown();

		void		signForm(AForm &form);
		void		executeForm(AForm const &form);
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


