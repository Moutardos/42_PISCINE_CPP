#include "AForm.hpp"

AForm::AForm (void) : _name("Unnamed AForm"), _signed(false), _reqGradeSign(150), _reqGradeExec(150) {}

AForm::AForm (AForm &other) : _name(other.getName()), _signed(other.getSigned()), _reqGradeSign(other.getReqGradeS()), _reqGradeExec(other.getReqGradeE()){

}

AForm &AForm::operator= (AForm &other)
{

	this->_signed = other.getSigned();
	return (*this);
}

AForm::~AForm (void) {}

AForm::AForm (std::string name, int sign, int gradeExec, int gradeSign) : _name(name),  _signed(sign),
_reqGradeSign(gradeSign), _reqGradeExec(gradeExec) {

	checkGrade(gradeExec);
	checkGrade(gradeSign);
}

void	AForm::beSigned	(Bureaucrat &bu)
{
	if (bu.getGrade() <= this->getReqGradeS())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
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

void getTarget (void) const {

	return (this->_target);
}

void setTarget (const std::string &target) {

	this->_target = target;
}

void AForm::checkGrade (int grade) {

	if (grade < 1)
		throw AForm::GradeTooHighException() ;
	if (grade > 150)
		throw AForm::GradeTooLowException() ;
}

std::ostream &operator<< (std::ostream &os, AForm &f)
{
	os << f.getName() << " Form, ";
	if (f.getSigned())
		os << "signed, ";
	else
		os << "not signed, ";
	os << "required grade to sign/exec : " << f.getReqGradeS() << "/" << f.getReqGradeE() << std::endl;
	return (os);
}