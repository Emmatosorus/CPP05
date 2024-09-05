#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "Bureaucrat.h"
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

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string targets );
		PresidentialPardonForm(const PresidentialPardonForm & p);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=( const PresidentialPardonForm & p );

		std::string		get_target() const;

		void	execute( Bureaucrat const & executor ) const;

	private:
		PresidentialPardonForm();
		std::string	target;
};


#endif
