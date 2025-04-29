#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Blackout", 150);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->gradeUp();
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Blackstart", 1);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->gradeDown();
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test" << std::endl;
		Bureaucrat *bureaucrat1 = new Bureaucrat("Blackout", 150);
		Bureaucrat *bureaucrat2 = new Bureaucrat("Blackstart", 1);
		std::cout << *bureaucrat1 << std::endl;
		std::cout << *bureaucrat2 << std::endl;
		try
		{
			bureaucrat1->gradeDown();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			bureaucrat2->gradeUp();	
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat1;
		delete bureaucrat2;
		std::cout << std::endl;
	}
	{
		std::cout << "Test" << std::endl;
		Bureaucrat *bureaucrat99 = new Bureaucrat("Electricity", 150);
		while(1)
		{
			try
			{
				bureaucrat99->gradeUp();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				return 1;
			}
		}
		delete bureaucrat99;
		std::cout << std::endl;
	}
	return (0);
}