#include "../includes/Bureaucrat.h"
#include "../includes/AForm.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/PresidentialPardonForm.h"


int main(void)
{
	std::cout << std::endl << "\x1b[1;36m############### TEST 1 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		ShrubberyCreationForm s = ShrubberyCreationForm("home");

		std::cout << std::endl;

		steve.signForm(s);
		std::cout << std::endl;
		s.execute(steve);

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 2 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		ShrubberyCreationForm s = ShrubberyCreationForm("park");

		std::cout << std::endl;
		s.execute(steve);

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 3 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		RobotomyRequestForm	r = RobotomyRequestForm("Bob");

		std::cout << std::endl;
		steve.signForm(r);
		std::cout << std::endl;
		r.execute(steve);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 4 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		RobotomyRequestForm	r = RobotomyRequestForm("Bob");

		std::cout << std::endl;
		r.execute(steve);

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 5 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		PresidentialPardonForm	r = PresidentialPardonForm("Bob");

		std::cout << std::endl;
		r.execute(steve);

		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 6 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(15, "Steve");
		PresidentialPardonForm	r = PresidentialPardonForm("Bob");

		std::cout << std::endl;
		steve.signForm(r);
		std::cout << std::endl;
		r.execute(steve);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 6 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(1, "Steve");
		PresidentialPardonForm	r = PresidentialPardonForm("Bob");

		std::cout << std::endl;
		steve.signForm(r);
		std::cout << std::endl;
		steve.executeForm(r);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 6 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(8, "Steve");
		PresidentialPardonForm	r = PresidentialPardonForm("Bob");

		std::cout << std::endl;
		steve.signForm(r);
		std::cout << std::endl;
		steve.executeForm(r);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 7 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Bureaucrat	steve = Bureaucrat(1, "Steve");
		PresidentialPardonForm	r = PresidentialPardonForm("Bob");

		std::cout << r << std::endl;
		steve.signForm(r);
		std::cout << std::endl;
		std::cout << r << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}