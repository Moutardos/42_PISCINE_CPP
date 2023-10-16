/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:52:50 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/16 18:29:25 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook (void) { 

	this->_size = 0;
	return;
}

Phonebook::~Phonebook (void) { }

bool	Phonebook::addNewContact (void) {

	Contact	new_contact = Contact();

	if (!new_contact.initialize("sample", "test", "stest", "0101", "i'm a robot beepboop"))
		return (false);
	if (this->_size < CONTACT_MAX)
	{
		this->_contacts[this->_size].copy(new_contact);
		this->_size++;
	}
	else
	{
		for (int i = 0; i < CONTACT_MAX - 1; i++)
		{
			this->_contacts[i].copy(this->_contacts[i + 1]);
		}
		this->_contacts[CONTACT_MAX - 1].copy(new_contact);
		this->_contacts[CONTACT_MAX - 1].setLname("finalboss");
	}
	return (true);
}

void	Phonebook::displayContacts(void) const{

	for (int i = 0; i < this->_size; i++)
	{
		this->_contacts[i].displayInfo();
	}
}