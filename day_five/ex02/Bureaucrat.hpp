#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

# include "AForm.hpp"
class AForm;

class Bureaucrat{

public:
	Bureaucrat	(void);
	Bureaucrat	(Bureaucrat &other);
	Bureaucrat	&operator= (Bureaucrat &other);
	~Bureaucrat	(void);

	Bureaucrat	(const std::string &name, int grade);

	int			getGrade 	(void) const;
	std::string	getName 	(void) const;

	void	increment	(void);
	void	decrement	(void);
	void	signForm	(AForm &form);
	void	executeForm	(AForm &form);
	static void	checkGrade (int grade);

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
	const std::string 	_name;
	int					_grade;
};

std::ostream	&operator<< (std::ostream &os, Bureaucrat &bu);

#endif
