/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:51:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/16 18:33:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{

	Phonebook phonebook = Phonebook();

	phonebook.addNewContact();
	phonebook.displayContacts();
	std::cout << "---" << std::endl;
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();
	phonebook.addNewContact();

	phonebook.displayContacts();

	return (0);
}