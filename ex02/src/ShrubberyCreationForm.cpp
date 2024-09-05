#include "../includes/ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	std::cout << "ShrubberyCreationForm : Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm : Constructor called" << std::endl;
	this->target = target + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &s) : AForm(s)
{
	std::cout << "ShrubberyCreationForm : Copy constructor called" << std::endl;
	this->target = s.get_target();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm : Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::get_target() const
{
	return this->target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->get_is_signed())
		throw NotSignedException();
	if (executor.get_grade() > this->get_exec_grade())
		throw GradeTooLowException();
	std::string filename = this->get_target();
	std::ofstream file(filename.c_str());
	if (!file)
	{
		std::cout << BOLD << RED << "ShrubberyCreationForm : couldn't open " << this->get_target() << END << std::endl;
		return ;
	}
	file << "               ,@@@@@@@,\n"
			"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			"       |o|        | |         | |\n"
			"       |.|        | |         | |\n"
			"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
	std::cout << BOLD << WHITE << "ShrubberyCreationForm created " << RED << this->get_name() << WHITE << " after being executed by " << executor.get_name() << END << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	AForm::operator=(s);
	this->target = s.get_target();
	return *this;
}