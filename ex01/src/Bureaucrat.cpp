#include "../includes/Bureaucrat.h"

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	this->message = "Grade is too high!";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	this->message = "Grade is too low!";
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

Bureaucrat::Bureaucrat( int grade , std::string name ) : name(name)
{
	std::cout << "Bureaucrat : Constructor called with grade : " << grade << std::endl;
	this->grade = 0;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & c) : name(c.get_name())
{
	this->grade = c.get_grade();
	std::cout << "Bureaucrat : Copy constructor called with grade : " << this->grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat &c)
{
	// We don't copy the name since it is const
	this->grade = c.get_grade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : Destructor called" << std::endl;
}

int Bureaucrat::get_grade() const
{
	return this->grade;
}

std::string Bureaucrat::get_name() const
{
	return this->name;
}

void Bureaucrat::increment()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << "Incremented " << this->name << " , grade is now " << this->grade << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << "Decremented " << this->name << " , grade is now " << this->grade << std::endl;

}

void Bureaucrat::signForm(Form &f)
{
	if (this->grade > f.get_sign_grade())
	{
		std::cout << this->name << " couldn't sign " << f.get_name() << " due to grade being too low" << std::endl;
		return;
	}
	f.beSigned(*this);
	std::cout << this->name << " signed " << f.get_name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt)
{
	os << dt.get_name() << ", bureaucrat grade " << dt.get_grade();
	return os;
}
