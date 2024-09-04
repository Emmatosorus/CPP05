#include "../includes/Bureaucrat.h"

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg)
{
	this->message = msg;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg)
{
	this->message = msg;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat : Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( int grade , const std::string name ) : name(name)
{
	std::cout << "Bureaucrat : Constructor called with grade : " << grade << std::endl;
	this->grade = 0;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade is too HIGH");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade is too LOW");
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : Destructor called" << std::endl;
}

int Bureaucrat::get_grade() const
{
	return this->grade;
}

const std::string Bureaucrat::get_name() const
{
	return this->name;
}

void Bureaucrat::increment()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("Grade is too HIGH");
	this->grade--;
	std::cout << "Incremented " << this->name << " , grade is now " << this->grade << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("Grade is too LOW");
	this->grade++;
	std::cout << "Decremented " << this->name << " , grade is now " << this->grade << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
	os << dt.get_name() << ", bureaucrat grade " << dt.get_grade();
	return os;
}
