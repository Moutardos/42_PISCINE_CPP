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

	int			toInt		(void) const;
	float		toFloat		(void) const;
	int			getRawBits	(void) const;
	void		setRawBits	(int const raw);

	bool			operator== 	(const Fixed &f2) const;
	bool			operator!=	(const Fixed &f2) const;
	bool			operator>=	(const Fixed &f2) const;
	bool			operator<=	(const Fixed &f2) const;
	bool			operator>	(const Fixed &f2) const;
	bool			operator<	(const Fixed &f2) const;
	Fixed			operator+	(const Fixed &f2) const;
	Fixed			operator-	(const Fixed &f2) const;
	Fixed			operator*	(const Fixed &f2) const;
	Fixed			operator/	(const Fixed &f2) const;
	Fixed&			operator++	();
	Fixed&			operator--	();	
	Fixed 			operator++	(int);	
	Fixed			operator--	(int);	
	Fixed			&operator=			(const Fixed &number);

	static Fixed		&min				(Fixed &f1, Fixed& f2);
	static const Fixed	&min				(const Fixed &f1, const Fixed& f2);
	static Fixed		&max				(Fixed &f1, Fixed& f2);
	static const Fixed	&max				(const Fixed &f1, const Fixed& f2);
	static int			getFixedPt			(void);
	static int			bitsToShift			(void);

private:
	static const int	_fixedPt = 8;

	int _number;

};

std::ostream	&operator<< (std::ostream &os, const Fixed &fixedNb);

#endif