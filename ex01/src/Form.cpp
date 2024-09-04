#include "../includes/Form.h"

Form::GradeTooHighException::GradeTooHighException()
{
	this->message = "Permission denied, grade too high";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooLowException::GradeTooLowException()
{
	this->message = "Permission denied, grade too low";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::Form()
: name("default"), sign_grade(0), exec_grade(0)
{
	std::cout << "Form : Default constructor called" << std::endl;

}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
: name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "Form : Constructor called" << std::endl;
	this->is_signed = false;
}

Form::Form( const Form & f)
: name(f.get_name()), sign_grade(f.get_sign_grade()), exec_grade(f.get_exec_grade())
{
	std::cout << "Form : Copy constructor called" << std::endl;
	this->is_signed = is_signed;
}

Form::~Form()
{
	std::cout << "Form : Destructor called" << std::endl;
}

Form &Form::operator=(const Form &f)
{
	// We don't copy any const variables
	this->is_signed = f.get_is_signed();
	return *this;
}

const std::string Form::get_name() const
{
	return this->name;
}

bool Form::get_is_signed() const
{
	return this->is_signed;
}

int Form::get_sign_grade() const
{
	return this->sign_grade;
}

int Form::get_exec_grade() const
{
	return this->exec_grade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.get_grade() <= this->sign_grade)
	{
		if (this->is_signed)
		{
			std::cout << "Form " << this->name << " is already signed" << std::endl;
			return ;
		}
		else
			this->is_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "/*********************" << std::endl;
	os << "Name : " << f.get_name() << std::endl;
	if (f.get_is_signed())
		os << "Signed : ✅" << std::endl;
	else
		os << "Signed : ❌" << std::endl;
	os << "Grade required to sign : " << f.get_sign_grade() << std::endl;
	os << "Grade required to execute : " << f.get_exec_grade() << std::endl;
	os << "/*********************" << std::endl;
	return os;
}