#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat( int grade , const std::string name );
		Bureaucrat( const Bureaucrat & c );
		~Bureaucrat();

		Bureaucrat & operator=( const Bureaucrat & c );

		const std::string get_name() const;
		int get_grade() const;

		void	increment();
		void	decrement();

	private:
		Bureaucrat();
		const std::string	name;
		int					grade;
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char * msg);
				~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char * msg);
				~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);

#endif
