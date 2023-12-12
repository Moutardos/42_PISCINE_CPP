#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

public:
	Fixed  (void);
	Fixed  (const Fixed &number);
	~Fixed (void);
	Fixed	&operator=(const Fixed &number);

	int		getRawBits (void) const;
	void	setRawBits (int const raw);

private:
	static const int	_fixedPt = 8;

	int _number;

};

#endif