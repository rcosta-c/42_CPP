#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm();

        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;

        static AForm *createPresidentialPardonForm(std::string const &target)
        {
            return new PresidentialPardonForm(target);
        }

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form);