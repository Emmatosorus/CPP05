#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define UNDER "\x1b[4m"
#define END "\x1b[0m"

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
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& dt);



#endif
