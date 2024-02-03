#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (void) : AForm("RobotomyRequestForm", false, 45, 72) {

	this->setTarget("Unkown");
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm &other) : AForm("RobotomyRequestForm", false, 45, 72) {

	this->setTarget(other.getTarget());
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (RobotomyRequestForm &other)
{
	
	this->setTarget(other.getTarget());
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("RobotomyRequestForm", false, 45, 72) {

	this->setTarget(target);
}
