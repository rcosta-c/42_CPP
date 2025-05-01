#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/* * Bureaucrat class
 * This class represents a bureaucrat with a name and a grade.
 * The grade is an integer value that determines the bureaucrat's level of authority.
 * The higher the grade, the lower the authority.
 * The class provides methods to get the bureaucrat's name and grade,
 * as well as methods to increase or decrease the grade.
 * It also includes exception classes for handling grade-related errors.
 */


 /*	* AForm class
 * This class represents a form that can be signed by a bureaucrat.
 * The form has a name, a signing grade, and an execution grade.
 * The form can be signed by a bureaucrat if the bureaucrat's grade is
 * equal to or higher than the form's signing grade.
 * The class provides methods to get the form's name, signing grade,
 * execution grade, and whether the form is signed or not.
 * It also includes exception classes for handling grade-related errors.
 * The class provides a method to sign the form by a bureaucrat.
 * If the bureaucrat's grade is too low, an exception is thrown.
 * The class also provides a method to execute the form by a bureaucrat.
 * If the bureaucrat's grade is too low, an exception is thrown.
 */


 int main()
{
	{
		std::cout << "---Test 1---" << std::endl;
		Intern someRandomIntern;
		AForm *rrf;
		AForm *random;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		try
		{
			random = someRandomIntern.makeForm("random", "Bender");
			std::cout << *random << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
		std::cout << *b1 << std::endl;
		b1->signForm(*rrf);
		Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 50);
		std::cout << *b2 << std::endl;
		b2->signForm(*rrf);
		b2->executeForm(*rrf);
		delete b1;
		delete b2;
		delete rrf;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "---Test 2---" << std::endl;
		Intern someRandomIntern;
		AForm *rrf;
		AForm *scf;
		AForm *ppf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		std::cout << *scf << std::endl;
		std::cout << *ppf << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
		std::cout << *b1 << std::endl;
		b1->signForm(*rrf);
		b1->signForm(*scf);
		b1->signForm(*ppf);
		Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 5);
		std::cout << *b2 << std::endl;
		b2->signForm(*rrf);
		b2->signForm(*scf);
		b2->signForm(*ppf);
		b2->executeForm(*rrf);
		b2->executeForm(*scf);
		b2->executeForm(*ppf);
		delete b1;
		delete b2;
		delete rrf;
		delete scf;
		delete ppf;
	}
}
