#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern: Copy constructor called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern: Assignment operator called" << std::endl;
    (void)copy;
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "Intern: Destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    AForm *(*form[3])(std::string const &target) = {
        &ShrubberyCreationForm::createShrubberyCreationForm,
        &RobotomyRequestForm::createRobotomyRequestForm,
        &PresidentialPardonForm::createPresidentialPardonForm
    };
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (form[i](target));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    throw AForm::FormCreationException();
}