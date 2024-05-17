#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <stdlib.h>
#include <time.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm	(void);
	RobotomyRequestForm	(RobotomyRequestForm &other);
	RobotomyRequestForm	&operator= (RobotomyRequestForm &other);

	RobotomyRequestForm	(std::string target);

	void executeAction	(void);

private:

};

#endif
