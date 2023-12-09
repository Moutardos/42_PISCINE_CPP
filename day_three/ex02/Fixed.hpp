#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

public:
	Fixed  (void);
	Fixed  (const Fixed &number);
	~Fixed (void);

	Fixed (int number);
	Fixed (float number);

	int		toInt		(void) const;
	float	toFloat		(void) const;
	int		getRawBits	(void) const;
	void	setRawBits	(int const raw);
	bool	isEqual		(Fixed &other) const;

	Fixed&	Fixed::operator++	();
	Fixed&	Fixed::operator--	();	
	Fixed 	Fixed::operator++	(int);	
	Fixed	Fixed::operator--	(int);	
	Fixed	&operator=			(const Fixed &number);

	static int	getFixedPt	(void);
	static int	bitsToShift	(void);

private:
	static const int	_fixedPt = 8;

	int _number;

};
std::ostream	&operator<< (std::ostream &os, const Fixed &fixedNb);
bool			operator== (const Fixed &f1, const Fixed &f2);
bool			operator!=(const Fixed &f1, const Fixed &f2);
bool			operator>=(const Fixed &f1, const Fixed &f2);
bool			operator<=(const Fixed &f1, const Fixed &f2);
bool			operator>(const Fixed &f1, const Fixed &f2);
bool			operator<(const Fixed &f1, const Fixed &f2);
Fixed			operator+(const Fixed &f1, const Fixed &f2);
Fixed			operator-(const Fixed &f1, const Fixed &f2);
Fixed			operator*(const Fixed &f1, const Fixed &f2);
Fixed			operator/(const Fixed &f1, const Fixed &f2);

#endif