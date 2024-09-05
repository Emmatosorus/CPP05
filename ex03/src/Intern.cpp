#include "../includes/Intern.h"

const char *Intern::UnknownForm::what() const throw()
{
	return "\x1b[31;1mCan't create unknown form\x1b[0m";
}

Intern::Intern()
{
	std::cout << "Intern : Default constructor" << std::endl;
}

Intern::Intern( const Intern & i )
{
	(void)i;
	std::cout << "Intern : Copy constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern : Destructor" << std::endl;
}

Intern & Intern::operator=( const Intern & i )
{
	(void)i;
	return *this;
}

AForm * Intern::makeForm(std::string name, std::string target)
{
	std::string list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = -1;
	while (++i < 3)
		if (name == list[i])
		{
			std::cout << "Intern created " << name << std::endl;
			break;
		}
	switch (i)
	{
		case 0 :
			return (new ShrubberyCreationForm(target));
		case 1 :
			return (new RobotomyRequestForm(target));
		case 2 :
			return (new PresidentialPardonForm(target));
		default :
			throw UnknownForm();
	}
}

