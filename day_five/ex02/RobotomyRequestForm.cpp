#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (void) : AForm("RobotomyRequestForm", false, 5, 25),
_target("Unnamed") {}

RobotomyRequestForm::RobotomyRequestForm	(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", false, 5, 25),
_target(other.getTarget()) {}

RobotomyRequestForm	&operator= (RobotomyRequestForm &other)
{
	
	this->_target = other.getTarget();
	return (*this);
}

RobotomyRequestForm	(std::string target);