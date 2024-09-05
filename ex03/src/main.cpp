#include "../includes/Bureaucrat.h"
#include "../includes/Intern.h"
#include "../includes/AForm.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/PresidentialPardonForm.h"


int main(void)
{
	std::cout << std::endl << "\x1b[1;36m############### TEST 1 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Intern	i = Intern();
		AForm	*ptr = i.makeForm("nfkdjbgkdjrhgkudbg", "bob");

		Bureaucrat b = Bureaucrat(2, "steve");
		ptr->execute(b);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 2 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Intern	i = Intern();
		AForm	*ptr = i.makeForm("shrubbery creation", "home");

		Bureaucrat b = Bureaucrat(2, "steve");
		b.signForm(*ptr);
		ptr->execute(b);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 3 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Intern	i = Intern();
		AForm	*ptr = i.makeForm("robotomy request", "bob");

		Bureaucrat b = Bureaucrat(2, "steve");
		b.signForm(*ptr);
		for (int x = 0; x < 5; x++)
			ptr->execute(b);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 4 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Intern	i = Intern();
		AForm	*ptr = i.makeForm("presidential pardon", "steve");

		Bureaucrat b = Bureaucrat(2, "steve");
		b.signForm(*ptr);
		ptr->execute(b);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
