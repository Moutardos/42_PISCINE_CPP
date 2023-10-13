/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:11:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/13 18:31:13 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string number,
 				std::string secret)
				: _fname(fname), _lname(lname), _nname(nname), _number(number), _secret(secret) {}

Contact::~Contact(void) {}

std::string getFname(void) const\{

	return (this->_fname);
}
std::string getLname(void) const {

	return (this->_lname);
}
std::string getNname(void) const {

	return (this->_nname);
}
std::string getNumber(void) const {

	return (this->_number);
}
std::string getSecret(void) const {

	return (this->_secret);
}

void	changeNumber(std::string number) {

	if (Contact::checkNumber(number))
		this->_number = _number;
}

static bool	checkNumber(std::string new_number) {
	
	for (std::string::iter it = new_number.begin(); it != new_number.end(); it++)
		if (!is_digit(it))
			return (false);
	return (true);
} 