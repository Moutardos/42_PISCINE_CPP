#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Form {

public:
	Form	(void);
	Form	(Form &other);
	Form	&operator= (Form &other);
	~Form	(void);

	void	beSigned	(Bureaucrat &bu);

	class GradeTooHighException : public std::exception 
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return "Grade can't be higher than 1";
			}
	
	};
	class GradeTooLowException : public std::exception 
	{
		public:
			virtual const char*	what(void) const throw()
			{
				return "Grade can't be lower than 150";
			}
	
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;
};

std::ostream	&operator<< (std::ostream &os, Bureaucrat &bu);

#endif
