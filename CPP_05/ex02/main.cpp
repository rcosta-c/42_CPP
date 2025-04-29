#include "Bureaucrat.hpp"
#include "Form.hpp"

/* * Bureaucrat class
 * This class represents a bureaucrat with a name and a grade.
 * The grade is an integer value that determines the bureaucrat's level of authority.
 * The higher the grade, the lower the authority.
 * The class provides methods to get the bureaucrat's name and grade,
 * as well as methods to increase or decrease the grade.
 * It also includes exception classes for handling grade-related errors.
 */

 /* * Form class
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
 * The class also provides a method to execute the form by a bureaucrat.
 * If the bureaucrat's grade is too low, an exception is thrown.
 */

 int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Light", 150);
		std::cout << *bureaucrat << std::endl;
		Form *form = new Form();
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		delete form;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Black", 150);
		Bureaucrat *b2 = new Bureaucrat("Start", 1);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		Form *form = new Form("Form", 1, 1);
		std::cout << *form << std::endl;
		try
		{
			form->beSigned(*b1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			form->beSigned(*b2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << *form << std::endl;
		delete form;
		delete b1;
		delete b2;
	}
}
