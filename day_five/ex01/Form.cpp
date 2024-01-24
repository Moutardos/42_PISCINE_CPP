#include "Form.hpp"

Form::Form (void) : _name("Unnamed Form"), _signed(false), _reqGradeExec(150), _reqGradeSign(150) {}

Form::Form (Form &other) : _name(other.getName()), _signed(),{


}

Form &operator= (Form &other);
~Form (void);

void	beSigned	(Bureaucrat &bu);

	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;

