#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;
class Form {

public:
	Form	(void);
	Form	(Form &other);
	Form	&operator= (Form &other);
	~Form	(void);
	Form	(std::string name, int sign, int gradeExec, int gradeSign);

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getReqGradeS(void) const;
	int			getReqGradeE(void) const;

	void	beSigned	(Bureaucrat &bu);

	static void	checkGrade	(int grade, int min = 150 , int max = 1);

	class GradeTooHighException : public std::exception 
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return "Grade is too high";
			}
	
	};
	class GradeTooLowException : public std::exception 
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return "Grade is too low";
			}
	
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;
};

std::ostream	&operator<< (std::ostream &os, Form &f);

#endif
