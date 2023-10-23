/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/20 19:14:28 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <iostream>
# if (CONTACT_MAX + 0 < 1) // Used to check if macro CONTACT_MAX is not an empty string
#  undef CONTACT_MAX       // and not under 1
#  define CONTACT_MAX 8
# endif

class Phonebook {

public:
	Phonebook	(void);
	~Phonebook	(void);

	void	start			(void);
	void	displayContacts	(void) const;

private:
	Contact		_contacts[CONTACT_MAX];
	int			_size;
	std::string	_input;

	bool	addNewContact	(Contact contact);
	bool	promptContact	(void);
	bool	promptSearch	(void);
	bool	prompt			(void);
	void	resetInput		(void);
};

# endif