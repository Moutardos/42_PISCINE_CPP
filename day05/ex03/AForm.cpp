#include "AForm.hpp"

AForm::AForm (void) : _name("Unnamed AForm"), _signed(false), _reqGradeSign(150), _reqGradeExec(150), _target("Unkown") {}

AForm::AForm (AForm &other) : _name(other.getName()), _signed(other.getSigned()), _reqGradeSign(other.getReqGradeS()), _reqGradeExec(other.getReqGradeE()),  _target(other.getTarget()) {}

AForm &AForm::operator= (AForm &other) {

	this->_signed = other.getSigned();
	return (*this);
}

AForm::~AForm (void) {}

AForm::AForm (const std::string &name, int sign, int gradeExec, int gradeSign) : _name(name),  _signed(sign),
_reqGradeSign(gradeSign), _reqGradeExec(gradeExec) {

	checkGrade(gradeExec);
	checkGrade(gradeSign);
}

void	AForm::beSigned	(Bureaucrat &bu) {

	AForm::checkGrade(bu.getGrade(), this->getReqGradeS());
	this->_signed = true;
}

std::string AForm::getName(void) const {

	return (this->_name);
}

bool AForm::getSigned(void) const {

	return (this->_signed);
}

int AForm::getReqGradeS(void) const {

	return (this->_reqGradeSign);
}

int AForm::getReqGradeE(void) const {

	return (this->_reqGradeExec);
}

std::string AForm::getTarget (void) const {

	return (this->_target);
}

void AForm::setTarget (const std::string &target) {

	this->_target = target;
}

void AForm::execute (Bureaucrat &bu) {

	checkGrade(bu.getGrade(), this->getReqGradeE());
	this->executeAction();
}

void AForm::checkGrade (int grade, int min, int max) {

	if (grade < max)
		throw AForm::GradeTooHighException() ;
	if (grade > min)
		throw AForm::GradeTooLowException() ;
}

std::ostream &operator<< (std::ostream &os, AForm &f) {

	os << f.getName() << " Form, ";
	if (f.getSigned())
		os << "signed, ";
	else
		os << "not signed, ";
	os << "required grade to sign/exec : " << f.getReqGradeS() << "/" << f.getReqGradeE() << std::endl;
	return (os);
}