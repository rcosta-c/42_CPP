#pragma once
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();



		void		GradeTooHighException();
		void		GradeTooLowException();
		std::string	getName();
		int			getGrade();

	protected/private:
		int 		_grade;
		std::string _name;




}