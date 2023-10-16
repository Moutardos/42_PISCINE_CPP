/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/16 18:30:02 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <iostream>
# define CONTACT_MAX 8

class Phonebook {

public:
	Phonebook	(void);
	~Phonebook	(void);

	bool	addNewContact	(void);
	void	displayContacts	(void) const;
private:
	Contact	_contacts[CONTACT_MAX];
	int		_size;
	void	shiftContact	(void);
};

# endif