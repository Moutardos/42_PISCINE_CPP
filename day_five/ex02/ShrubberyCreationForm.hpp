#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm {

public:
	ShrubberyCreationForm	(void);
	ShrubberyCreationForm	(ShrubberyCreationForm &other);
	ShrubberyCreationForm	&operator= (ShrubberyCreationForm &other);

	ShrubberyCreationForm	(std::string target);

private:

};

#endif
