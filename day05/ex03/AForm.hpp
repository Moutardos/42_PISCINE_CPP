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
	AForm	(const std::string &name, int sign, int gradeExec, int gradeSign);

	std::string	getName			(void) const;
	bool		getSigned		(void) const;
	int			getReqGradeS	(void) const;
	int			getReqGradeE	(void) const;
	void		beSigned		(Bureaucrat &bu);
	void		execute			(Bureaucrat &bu);

	virtual void	executeAction	(void) = 0;

	static void	checkGrade	(int grade, int min = 150, int max = 1);

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


protected:
	void		setTarget	(const std::string &target);
	std::string	getTarget	(void) const;

private:
	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;
	std::string			_target;
};

std::ostream	&operator<< (std::ostream &os, AForm &f);

#endif
