/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:12:08 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/09 19:35:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
int	main(void) {
	{
		Fixed a;
		Fixed const b( 1 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		Fixed e;

		a = Fixed( -10.1f );
		e = b + c;

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "e is " << e << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;

		if (b == 1)
			std::cout << "a == 1" << std::endl;
		if (a == b)
			std::cout << "a == b" << std::endl;
		if (b == d)
			std::cout << "b == d" << std::endl;
		if (d >= a)
			std::cout << "d >= a" << std::endl;
		if (b < d)
			std::cout << "b < d" << std::endl;
		if (a != a)
			std::cout << "a != a" << std::endl;
		if (a <= a)
			std::cout << "a <= a" << std::endl;

		std::cout << std::endl;
	}
	Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 0 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}