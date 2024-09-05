#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <fstream>
#include "AForm.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define UNDER "\x1b[4m"
#define END "\x1b[0m"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm & s );
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=( const ShrubberyCreationForm & s );

		std::string	get_target() const;

		void	execute( Bureaucrat const & executor ) const;

	private:
		ShrubberyCreationForm();
		std::string	target;
};

#endif
