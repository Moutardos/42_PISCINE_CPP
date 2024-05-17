/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/30 13:56:21 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# if (CONTACT_MAX + 0 < 1 || CONTACT_MAX > 100)
#  undef CONTACT_MAX                            
#  define CONTACT_MAX 8
# endif

class Phonebook {

public:
	Phonebook	(void);
	~Phonebook	(void);

	void		start			(void);
	void		displayContacts	(void) ;
	static void	displayColumn	(std::string text, bool legend=false);

private:
	Contact			_contacts[CONTACT_MAX];
	unsigned int	_size;
	unsigned int	_currId;
	std::string		_input;

	bool		addNewContact	(Contact contact);
	bool		promptContact	(void);
	bool		promptSearch	(void);
	bool		prompt			(void);

};

# endif

