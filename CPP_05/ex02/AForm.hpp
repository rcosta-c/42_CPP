#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &bureaucrat);
        void beExecuted(Bureaucrat const &bureaucrat) const = 0;
        virtual void execute(Bureaucrat const &executor) const;


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

    protected:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, AForm &form);