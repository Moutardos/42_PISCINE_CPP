/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:25:55 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/09 18:49:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void) {

	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}
Fixed::Fixed (const Fixed &number)  {

	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &number) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = number.getRawBits();
	return (*this);
}

Fixed::Fixed (int number) {

	this->_number = number;
	this->_number = this->_number << this->_fixedPt;
}

// 
Fixed::Fixed (float number) {

	float	shiftNumber = number * Fixed::bitsToShift();
	int		numberShifted = static_cast<int> (roundf(shiftNumber));
	if (numberShifted < 0)
	{
		numberShifted *= -1;
		numberShifted = ~ numberShifted;
	}
	this->_number = numberShifted;
}


int		Fixed::getRawBits (void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

int		Fixed::getFixedPt (void) {

	return (_fixedPt);
}

void	Fixed::setRawBits (int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

int	Fixed::toInt (void) const {

	return (this->_number >> this->_fixedPt);
}

float	Fixed::toFloat (void) const {

	return (static_cast<float> (this->_number) / static_cast<float> (Fixed::bitsToShift()));
}

int	Fixed::bitsToShift (void) {

	int 		res = 1;
	int const	FixedPt = Fixed::getFixedPt();

	for (int i = 0; i < FixedPt; i++)
		res *= 2;
	return (res);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixedNb)
{
	os << fixedNb.toFloat();
	return (os);
}