#ifndef INTERN_H
# define INTERN_H

# define FORM_MAX 4
# define FORMS_NAMES {"presidential pardon", "robotomy request", "shrubbery creation"}
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {

public:
	Intern	(void);
	~Intern	(void);
	AForm	*makeForm(std::string formName, std::string target);

	class FormError : public std::exception 
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return "Form request doesn't exist";
			}
	
	};

private:
	Intern	(Intern &other);
	Intern	&operator= (Intern &other);

};

#endif
