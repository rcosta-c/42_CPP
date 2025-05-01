#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		 std::cout << "Test 1" << std::endl;
		 std::cout << "Failed Tests" << std::endl;
		 Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
		 std::cout << *bureaucrat << std::endl;
		 ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		 std::cout << *shrubbery << std::endl;
		 bureaucrat->signForm(*shrubbery);
		 bureaucrat->executeForm(*shrubbery);
		 RobotomyRequestForm *robotomy = new RobotomyRequestForm("Home");
		 std::cout << *robotomy << std::endl;
		 bureaucrat->signForm(*robotomy);
		 bureaucrat->executeForm(*robotomy);
		 PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");
		 std::cout << *presidential << std::endl;
		 bureaucrat->signForm(*presidential);
		 bureaucrat->executeForm(*presidential);
		 delete bureaucrat;
		 delete shrubbery;
		 delete robotomy;
		 delete presidential;
		 std::cout << std::endl;
	 }
	 {
		 std::cout << "------Test 2------" << std::endl;
		 std::cout << "------Sucessuful Test------" << std::endl;
		 Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 1);
		 std::cout << *bureaucrat << std::endl;
		 ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		 std::cout << *shrubbery << std::endl;
		 bureaucrat->signForm(*shrubbery);
		 bureaucrat->executeForm(*shrubbery);
		 RobotomyRequestForm *robotomy = new RobotomyRequestForm("Robocop");
		 std::cout << *robotomy << std::endl;
		 bureaucrat->signForm(*robotomy);
		 bureaucrat->executeForm(*robotomy); //50% chance of success
		 PresidentialPardonForm *presidential = new PresidentialPardonForm("Emilio");
		 std::cout << *presidential << std::endl;
		 bureaucrat->signForm(*presidential);
		 bureaucrat->executeForm(*presidential);
		 delete bureaucrat;
		 delete shrubbery;
		 delete robotomy;
		 delete presidential;
		 std::cout << std::endl;
	 }
 }
