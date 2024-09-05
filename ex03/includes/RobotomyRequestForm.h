#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <fstream>
#include <cstdlib>
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

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target );
		RobotomyRequestForm( const RobotomyRequestForm & r );
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=( const RobotomyRequestForm & r);

		std::string get_target() const;

		void	execute( Bureaucrat const & executor ) const;

	private:
		RobotomyRequestForm();
		std::string	target;
};


#endif
