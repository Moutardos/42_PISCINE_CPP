#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm {

public:
	PresidentialPardonForm	(void);
	PresidentialPardonForm	(PresidentialPardonForm &other);
	PresidentialPardonForm	&operator= (PresidentialPardonForm &other);

	PresidentialPardonForm	(std::string target);

private:

};

#endif
