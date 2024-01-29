#include "Form.hpp"

Form::Form (void) : _name("Unnamed Form"), _signed(false), _reqGradeSign(150), _reqGradeExec(150) {}

Form::Form (Form &other) : _name(other.getName()), _signed(other.getSigned()), _reqGradeSign(other.getReqGradeS()), _reqGradeExec(other.getReqGradeE()){

}

Form &Form::operator= (Form &other)
{

	this->_signed = other.getSigned();
	return (*this);
}

Form::~Form (void) {}

Form::Form (std::string name, int sign, int gradeExec, int gradeSign) : _name(name),  _signed(sign),
_reqGradeSign(gradeSign), _reqGradeExec(gradeExec) {

	checkGrade(gradeExec);
	checkGrade(gradeSign);
}

void	Form::beSigned	(Bureaucrat &bu)
{
	if (bu.getGrade() <= this->getReqGradeS())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName(void) const {

	return (this->_name);
}

bool Form::getSigned(void) const {

	return (this->_signed);
}

int Form::getReqGradeS(void) const {

	return (this->_reqGradeSign);
}

int Form::getReqGradeE(void) const {

	return (this->_reqGradeExec);
}

void Form::checkGrade (int grade) {

	if (grade < 1)
		throw Form::GradeTooHighException() ;
	if (grade > 150)
		throw Form::GradeTooLowException() ;
}

std::ostream &operator<< (std::ostream &os, Form &f)
{
	os << f.getName() << " form, ";
	if (f.getSigned())
		os << "signed, ";
	else
		os << "not signed, ";
	os << "required grade to sign/exec : " << f.getReqGradeS() << "/" << f.getReqGradeE() << std::endl;
	return (os);
}