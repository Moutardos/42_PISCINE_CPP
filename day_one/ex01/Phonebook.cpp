/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:52:50 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/17 19:30:16 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void) { 

	this->_size = 0;
	return;
}

Phonebook::~Phonebook(void) { }

void	Phonebook::start(void) {

	bool	end = false;

	while (!end)
	{
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		this->prompt();
		std::cout << "read : " << this->_input << std::endl;
		if (!this->_input.compare("ADD"))
			this->promptContact();
		else if (!this->_input.compare("SEARCH"))
			this->promptSearch();
		else if (!this->_input.compare("EXIT"))
			end = true;
		this->_input = "";
	}
	return;
}

bool	Phonebook::promptContact(void) {

	Contact	new_contact;

	this->_input = "";
	do
	{
		std::cout << "Last name: ";
		this->prompt();
	} while (!new_contact.setLname(this->_input));
	return (true);
}

bool	Phonebook::promptSearch(void) {

	std::cout << "sese\n";
	return (true);
}

void	Phonebook::prompt(void) {

	std::cin >> this->_input;
}
bool	Phonebook::addNewContact(Contact contact) {

	if (contact.empty())
		return (false);
	if (this->_size < CONTACT_MAX)
	{
		this->_contacts[this->_size].copy(contact);
		this->_size++;
	}
	else
	{
		for (int i = 0; i < CONTACT_MAX - 1; i++)
		{
			this->_contacts[i].copy(this->_contacts[i + 1]);
		}
		this->_contacts[CONTACT_MAX - 1].copy(contact);
	}
	return (true);
}

void	Phonebook::displayContacts(void) const{

	for (int i = 0; i < this->_size; i++)
	{
		this->_contacts[i].displayInfo();
	}
}