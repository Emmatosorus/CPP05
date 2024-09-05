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

class AForm
{
	public:
		AForm(std::string name, int sign_grade, int exec_grade );
		AForm(const AForm & f );
		virtual ~AForm() = 0;

		AForm & operator=(const AForm & f );

		const std::string	get_name() const;
		bool				get_is_signed() const;
		int					get_sign_grade() const;
		int					get_exec_grade() const;

		void	beSigned( Bureaucrat & b );
		virtual void execute( Bureaucrat const & executor ) const = 0;

	protected:
		AForm();

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

		class NotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};

	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;
};

std::ostream& operator<<(std::ostream& os, const AForm& dt);


#endif
