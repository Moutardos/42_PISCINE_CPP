#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm	(void);
	PresidentialPardonForm	(PresidentialPardonForm &other);
	PresidentialPardonForm	&operator= (PresidentialPardonForm &other);

	PresidentialPardonForm	(std::string target);

	std::string	getTarget	(void) const;

private:
	const std::string	_target;

};

#endif
