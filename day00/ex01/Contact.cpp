/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:11:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/05/08 16:13:59 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _fname(""), _lname(""), _nname(""), _number(""), _secret("") {}

Contact::~Contact(void) {}

std::string	Contact::getFname(void) const{

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

bool	Contact::setLname(std::string lname) {

	if (!lname.empty() && Contact::checkName(lname))
		this->_lname = lname;
	else
	{
		std::cout << "This isn't a valid last name" << std::endl;
		return (false);
	}
	return (true);

}

bool	Contact::setFname(std::string fname) {

	if (!fname.empty() && Contact::checkName(fname))
		this->_fname = fname;
	else
	{
		std::cout << "This isn't a valid first name" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::setNname(std::string nname) {

	if (!nname.empty() && Contact::checkName(nname))
		this->_nname = nname;
	else
	{
		std::cout << "This isn't a valid nickname" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::setNumber(std::string number) {

	if (!number.empty() && Contact::checkNumber(number))
		this->_number = number;
	else
	{
		std::cout << "This isn't a valid phone number" << std::endl;
		return (false);
	}
	return (true);

}

bool	Contact::setSecret(std::string secret) {

	if (!secret.empty())
		this->_secret = secret;
	else
	{
		std::cout << "You surely have a secret, don't you ?" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::checkNumber(std::string number) {
	
	for (std::string::iterator it = number.begin(); it != number.end(); it++)
		if (!std::isdigit(*it))
			return (false);
	return (true);
}

bool	Contact::checkName(std::string name) {
	
	for (std::string::iterator it = name.begin(); it != name.end(); it++)
		if (!::isalpha(*it))
			return (false);
	return (true);
}

void	Contact::resetContact(void) {

	this->_fname = "";
	this->_lname = "";
	this->_nname = "";
	this->_number = "";
	this->_secret = "";
	return ;
}

void	Contact::copy(Contact &contact){

	this->_fname = contact._fname;
	this->_lname = contact._lname;
	this->_nname = contact._nname;
	this->_number = contact._number;
	this->_secret = contact._secret;
}

bool	Contact::empty(void) const {

	return (this->_fname.empty() || this->_lname.empty() || 
			this->_nname.empty() || this->_number.empty() || this->_secret.empty());
}

void	Contact::displayInfo(void) const {

	if (!this->empty())
	{
		std::cout << "Coucou je suis " << this->_fname << std::endl << "Nom de famille: " << this->_lname;
		std::cout << "\nmon pseudonyme est " << this->_nname << "!\nMon numéro de tel : " << this->_number;
		std::cout << "\nEt \"" << this->_secret << "\" mais ne le dis à personne hein!" << std::endl;
	}
	return ;
}