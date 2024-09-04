#include "../includes/Bureaucrat.h"


int main(void)
{
	std::cout << std::endl << "\x1b[1;36m############### TEST 1 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat steve = Bureaucrat(0, "steve");
		std::cout << steve << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 2 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat bob = Bureaucrat( 151 , "bob" );
		std::cout << bob << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 3 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat alex = Bureaucrat(25, "alex");
		std::cout << alex << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 4 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat chad = Bureaucrat(2, "chad");
		std::cout << chad << std::endl;
		chad.increment();
		chad.increment();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 5 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat karen = Bureaucrat(149, "karen");
		std::cout << karen << std::endl;
		karen.decrement();
		karen.decrement();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}