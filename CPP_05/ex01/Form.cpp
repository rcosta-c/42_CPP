#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form: Constructor called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form: Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        std::cout << "Form: Assignment operator called" << std::endl;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form: Destructor called" << std::endl;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    std::cout << "Form name: " << form.getName();
    std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    std::cout << "Grade to sign: " << form.getGradeToSign();
    std::cout << "Grade to execute: " << form.getGradeToExecute();
    return out;
}