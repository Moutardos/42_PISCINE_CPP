/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:51:35 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/17 19:19:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook phonebook = Phonebook();


	std::cout << "value of CONTACT_MAX" << CONTACT_MAX << std::endl;
	phonebook.displayContacts();
	phonebook.start();
	return (0);
}