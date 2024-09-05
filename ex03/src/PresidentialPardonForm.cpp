#include "../includes/PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	std::cout << "PresidentialPardonForm : Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	std::cout << "PresidentialPardonForm : Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p)
{
	this->target = p.get_target();
	std::cout << "PresidentialPardonForm : Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : Destructor called" << std::endl;
}

std::string PresidentialPardonForm::get_target() const
{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->get_is_signed())
		throw NotSignedException();
	if (executor.get_grade() > this->get_exec_grade())
		throw GradeTooLowException();
	std::cout << BOLD << WHITE << this->target << " has been pardoned by Zaphod Beeblebrox" << END << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	AForm::operator=(p);
	this->target = p.get_target();
	return *this;
}