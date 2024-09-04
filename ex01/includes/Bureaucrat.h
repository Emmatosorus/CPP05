#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "Form.h"

class Form;

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

		void	signForm(Form & f);

	private:
		Bureaucrat();

		const std::string	name;
		int					grade;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException();
				~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException();
				~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);

#endif
