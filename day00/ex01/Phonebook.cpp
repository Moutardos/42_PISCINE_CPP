/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:52:50 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/30 13:57:00 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) { 

	this->_size = 0;
	this->_currId = 0;
	return;
}

Phonebook::~Phonebook(void) { }

void	Phonebook::start(void) {

	bool	end = false;

	while (!end)
	{
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		if (!this->prompt())
			end = true;
		else if (!this->_input.compare("ADD"))
			this->promptContact();
		else if (!this->_input.compare("SEARCH"))
			this->promptSearch();
		else if (!this->_input.compare("EXIT"))
			end = true;
	}
	return;
}

bool	Phonebook::promptContact(void) {

	Contact	new_contact;

	std::cout << std::endl;
	do
	{
		std::cout << "First name: ";
		if (!this->prompt())
			return (false);
	} while (!new_contact.setFname(this->_input));
	do
	{
		std::cout << "Last name: ";
		if (!this->prompt())
			return (false);
	} while (!new_contact.setLname(this->_input));
	do
	{
		std::cout << "Nickname: ";
		if (!this->prompt())
			return (false);
	} while (!new_contact.setNname(this->_input));
	do
	{
		std::cout << "Phone number: ";
		if (!this->prompt())
			return (false);
	} while (!new_contact.setNumber(this->_input));
	do
	{
		std::cout << "Secret: ";
		if (!this->prompt())
			return (false);
	} while (!new_contact.setSecret(this->_input));
	std::cout << std::endl;
	return (this->addNewContact(new_contact));
}

bool	Phonebook::promptSearch(void) {

	unsigned int	id;

	this->displayContacts();
	if (this->_size > 0)
	{
		std::cout << "\nID: ";
		if (!this->prompt())
			return (false);
		if (Contact::checkNumber(this->_input))
		{
			std::stringstream(this->_input) >> id;
			if (id >= 0 && id < this->_size)
				this->_contacts[id].displayInfo();
		}
	}
	return (true);
}

bool	Phonebook::prompt(void) {

	if (!std::cin)
		return (false);
	std::getline(std::cin, this->_input);
	if (std::cin.eof())
		return (false);
	return (true);
}

bool	Phonebook::addNewContact(Contact contact) {

	if (contact.empty())
		return (false);
	if (this->_currId >= CONTACT_MAX)
		this->_currId = 0;
	if (this->_size < CONTACT_MAX)
		this->_size++;
	this->_contacts[this->_currId].copy(contact);
	this->_currId++;
	return (true);
}

void	Phonebook::displayContacts(void) {

	Contact 		current;

	std::cout << "|";
	Phonebook::displayColumn("Index");
	Phonebook::displayColumn("First name", true);
	Phonebook::displayColumn("Last name");
	Phonebook::displayColumn("Nickname");
	std::cout << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
	{
		current = this->_contacts[i];
		std::cout << "|";
		Phonebook::displayColumn(std::to_string(i));
		Phonebook::displayColumn(current.getFname());
		Phonebook::displayColumn(current.getLname());
		Phonebook::displayColumn(current.getNname());
		std::cout << std::endl;
	}
}

void	Phonebook::displayColumn(std::string text, bool legend) {

	if (text.length() >= 10 && !legend)
		text.replace(9, text.length(), ".");
	std::cout << std::setw(10) << text;
	std::cout << "|";
}