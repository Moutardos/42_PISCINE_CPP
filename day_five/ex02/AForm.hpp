#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;
class AForm {

public:
	AForm	(void);
	AForm	(AForm &other);
	AForm	&operator= (AForm &other);
	virtual ~AForm	(void);

	AForm	(std::string name, int sign, int gradeExec, int gradeSign);

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getReqGradeS(void) const;
	int			getReqGradeE(void) const;

	void	beSigned	(Bureaucrat &bu);

	static void	checkGrade (int grade);

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

std::ostream	&operator<< (std::ostream &os, AForm &f);

#endif
