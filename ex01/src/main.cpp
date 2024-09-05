#include "../includes/Bureaucrat.h"
#include "../includes/Form.h"


int main(void)
{
	std::cout << std::endl << "\x1b[1;36m############### TEST 1 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		Form		b = Form( "b42", 42, 10);
		std::cout << steve << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 2 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		Form		b = Form( "b42", 42, 10);

		std::cout << std::endl;

		std::cout << b;
		steve.signForm(b);
		std::cout << b;

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 3 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob = Bureaucrat(15, "Bob");
		Form		b = Form( "b21", 2, 10);

		std::cout << std::endl;

		std::cout << b;
		bob.signForm(b);
		std::cout << b;

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 4 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	alex = Bureaucrat(15, "Alex");
		Form		b = Form( "b21", 2, 10);

		std::cout << std::endl;

		std::cout << b;
		b.beSigned(alex);
		std::cout << b;

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 5 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	kerman = Bureaucrat(15, "Kerman");
		Form		b = Form( "b21", 42, 10);

		std::cout << std::endl;

		std::cout << b;
		b.beSigned(kerman);
		std::cout << b;

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}