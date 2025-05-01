#pragma once
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <ctime>


class Bureaucrat;

class AForm
{
    public:
        
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &bureaucrat);
        void beExecuted(Bureaucrat const &bureaucrat) const;
        virtual void execute(Bureaucrat const & executor) const = 0;


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

        class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
        class FileNotOpenedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        class FormCreationException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        
    protected:
        AForm(void);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
};

std::ostream &operator<<(std::ostream &out, AForm &form);