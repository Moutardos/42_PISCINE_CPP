/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:11:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/14 19:58:01 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string number,
 				std::string secret)
				: _fname(fname), _lname(lname), _nname(nname), _number(number), _secret(secret) {}

Contact::Contact(void) : _fname(""), _lname(""), _nname(""), _number(""), _secret("") {}

Contact::~Contact(void) {}

std::string	Contact::getFname(void) const {

	return (this->_fname);
}
std::string	Contact::getLname(void) const{

	return (this->_lname);
}
std::string	Contact::getNname(void) const {

	return (this->_nname);
}
std::string	Contact::getNumber(void) const {

	return (this->_number);
}
std::string	Contact::getSecret(void) const {

	return (this->_secret);
}

void	Contact::changeNumber(std::string number) {

	if (Contact::checkNumber(number))
	{
		this->_number = number;
	}
	else
	{
		std::cout << "This isn't a valid phone number" << std::endl;
	}
}

bool	Contact::checkNumber(std::string new_number) {
	
	for (std::string::iterator it = new_number.begin(); it != new_number.end(); it++)
	{
		if (!::isdigit(*it))
			return (false);
	}
	return (true);
}

void	Contact::displayInfo(void) const {

	
	std::cout << "Coucou je suis" << this->_fname << " " << this->_lname;
	std::cout << "mais mes amis m'apelle " << this->_nname << "!\n Mon num : " << this->_number;
	std::cout << "et \"" << this->_secret << "\" mais ne le dis a personne hein!" << std::endl;
}