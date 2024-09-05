#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "AForm.h"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat( int grade , std::string name );
		Bureaucrat( const Bureaucrat & c );
		~Bureaucrat();

		Bureaucrat & operator=( Bureaucrat & c );

		std::string get_name() const;
		int get_grade() const;

		void	increment();
		void	decrement();

		void	signForm(AForm & f);
		void	executeForm(AForm const & form);

	private:
		Bureaucrat();

		const std::string	name;
		int					grade;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);

#endif
