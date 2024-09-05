#ifndef INTERN_H
#define INTERN_H


#include <iostream>
#include "AForm.h"
#include "../includes/ShrubberyCreationForm.h"
#include "../includes/RobotomyRequestForm.h"
#include "../includes/PresidentialPardonForm.h"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern & i);

		Intern & operator=( const Intern & i );

		AForm * makeForm(std::string name, std::string target);

		class UnknownForm : public std::exception
		{
			public:
				const char * what() const throw();
		};
};


#endif
