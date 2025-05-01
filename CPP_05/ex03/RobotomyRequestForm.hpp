#pragma once 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();

        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;

        static AForm *createRobotomyRequestForm(std::string const &target)
        {
            return new RobotomyRequestForm(target);
        }

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &form);