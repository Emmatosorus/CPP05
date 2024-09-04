#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	public:
		Form( std::string name, int sign_grade, int exec_grade );
		Form( const Form & f );
		~Form();

		Form & operator=( const Form & f );

		const std::string	get_name() const;
		bool				get_is_signed() const;
		int					get_sign_grade() const;
		int					get_exec_grade() const;

		void	beSigned( Bureaucrat & b );

	private:
		Form();

		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;

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

std::ostream& operator<<(std::ostream& os, const Form& dt);



#endif