#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm	(void);
	ShrubberyCreationForm	(ShrubberyCreationForm &other);
	ShrubberyCreationForm	&operator= (ShrubberyCreationForm &other);

	ShrubberyCreationForm	(std::string target);

	void executeAction	(void);

private:

	std::ofstream 	_file;
	std::string		_fname;
};

#endif
