#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"

class Intern {

public:
	Intern	(void);
	Intern	(Intern &other);
	Intern	&operator= (Intern &other);
	~Intern	(void);

private:
	AForm	*makeForm(std::string formName, std::string target);
};

#endif
