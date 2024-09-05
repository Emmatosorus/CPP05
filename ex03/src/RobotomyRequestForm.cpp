#include "../includes/RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm : Constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r)
{
	std::cout << "RobotomyRequestForm : Copy constructor called" << std::endl;
	this->target = r.get_target();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : Destructor called" << std::endl;
}

std::string RobotomyRequestForm::get_target() const
{
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static int rounds = 0;

	rounds++;
	srand(time(0));
	if (!this->get_is_signed())
		throw NotSignedException();
	if (executor.get_grade() > this->get_exec_grade())
		throw GradeTooLowException();
	int i = 0;
	int random;
	while (i++ < rounds)
		random = rand();
	std::cout << BOLD << WHITE << "Brrrrrrrrrrrrrrrrrrr" << END << std::endl;
	if (random % 2)
		std::cout << BOLD << WHITE << "RobotomyRequestForm : Robotomized " << this->get_target() << " successfully!" << END << std::endl;
	else
		std::cout << BOLD << WHITE << "RobotomyRequestForm : Robotomized " << this->get_target() << " unsuccessfully.." << END << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	AForm::operator=(r);
	this->target = r.get_target();
	return *this;
}