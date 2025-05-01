#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
    std::cout << "Aform: Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : 
    _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExecute), _isSigned(false)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Aform: Constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Aform: Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        std::cout << "Aform: Assignment operator called" << std::endl;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Aform: Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}   

std::ostream &operator<<(std::ostream &out, AForm &form)
{
    std::cout << "Form name: " << form.getName();
    std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    std::cout << "Grade to sign: " << form.getGradeToSign();
    std::cout << "Grade to execute: " << form.getGradeToExecute();
    return out;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

const char* AForm::FileNotOpenedException::what() const throw()
{
    return ("Could not open file");
}

const char* AForm::FormCreationException::what() const throw()
{
    return ("Form creation failed");
}