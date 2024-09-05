#include "../includes/AForm.h"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "\x1b[31;1mPermission denied, grade too high\x1b[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "\x1b[31;1mPermission denied, grade too low\x1b[0m";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "\x1b[31;1mTried to execute unsigned form\x1b[0m";
}

AForm::AForm() : name("default"), sign_grade(0), exec_grade(0)
{
	std::cout << "AForm : Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "AForm : Constructor called" << std::endl;
	this->is_signed = false;
}

AForm::AForm(const AForm & f) : name(f.get_name()), sign_grade(f.get_sign_grade()), exec_grade(f.get_exec_grade())
{
	std::cout << "AForm : Copy constructor called" << std::endl;
	this->is_signed = f.get_is_signed();
}

AForm::~AForm()
{
	std::cout << "AForm : Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &f)
{
	// We don't copy any const variables
	this->is_signed = f.get_is_signed();
	return *this;
}

const std::string AForm::get_name() const
{
	return this->name;
}

bool AForm::get_is_signed() const
{
	return this->is_signed;
}

int AForm::get_sign_grade() const
{
	return this->sign_grade;
}

int AForm::get_exec_grade() const
{
	return this->exec_grade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.get_grade() <= this->sign_grade)
	{
		if (this->is_signed)
		{
			std::cout << WHITE << BOLD << "AForm " << this->name << " is already signed" << END << std::endl;
			return ;
		}
		else
			this->is_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os <<  CYAN <<  "/*********************" << END << std::endl;
	os << UNDER << WHITE << "Name :" << END << " " << f.get_name() << std::endl;
	if (f.get_is_signed())
		os << UNDER << WHITE << "Signed :" << END << " ✅" << std::endl;
	else
		os << UNDER << WHITE << "Signed :" << END << " ❌" << std::endl;
	os << UNDER << WHITE << "Grade required to sign :" << END << " " << f.get_sign_grade() << std::endl;
	os << UNDER << WHITE << "Grade required to execute :" << END << " " << f.get_exec_grade() << std::endl;
	os <<  CYAN <<  "/*********************" << END << std::endl;
	return os;
}