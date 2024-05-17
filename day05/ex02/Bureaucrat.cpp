#include "Bureaucrat.hpp"

std::ostream &operator<< (std::ostream &os, Bureaucrat &bu) {

	os<< bu.getName() << ", bureaucrat grade " << bu.getGrade() << std::endl;
	return (os);
}

Bureaucrat::Bureaucrat (void) : _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat (Bureaucrat &other) : _name(other.getName()) {

	*this = other;
}


Bureaucrat &Bureaucrat::operator= (Bureaucrat &other) {

	this->_grade = other.getGrade();
	return (*this);
}


Bureaucrat::~Bureaucrat (void) {}


Bureaucrat::Bureaucrat (const std::string &name, int grade) : _name(name), _grade(grade) {

	Bureaucrat::checkGrade(grade);
}

int Bureaucrat::getGrade (void) const {

	return (this->_grade);
}
std::string	Bureaucrat::getName (void) const {

	return (this->_name);
}
void Bureaucrat::increment	(void) {

	Bureaucrat::checkGrade(this->_grade - 1);
	this->_grade--;
}
void Bureaucrat::decrement	(void) {

	Bureaucrat::checkGrade(this->_grade + 1);
	this->_grade++;
}

void	Bureaucrat::checkGrade (int grade) {

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException() ;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException() ;
}

void Bureaucrat::signForm (AForm &form) {

	try 
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm (AForm &form) {

	try 
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}