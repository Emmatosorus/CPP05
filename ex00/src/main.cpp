#include "../includes/Bureaucrat.h"


int main(void)
{
	{
		try
		{
			Bureaucrat steve = Bureaucrat(0, "steve");
			std::cout << steve << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat bob = Bureaucrat( 151 , "bob" );
			std::cout << bob << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat alex = Bureaucrat(25, "alex");
			std::cout << alex << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}