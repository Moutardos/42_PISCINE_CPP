#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (void) : AForm("RobotomyRequestForm", false, 45, 72) {

	this->setTarget("Unknown");
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

void RobotomyRequestForm::executeAction	(void) {

	std::cout << "Performing lobotomy on " << this->getTarget() << " bipboop.." << std::endl;
	if (rand() % 2)
		std::cout << "... Sucessful ! phew.." << std::endl;
	else
		std::cout << "... ahem something bad happened.." << std::endl;
}