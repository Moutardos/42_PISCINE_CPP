/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/14 20:02:50 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <iostream>

class Phonebook {

public:
	Phonebook (void);
	~Phonebook (void);

private:
	Contact _contacts[8] =
	{
		Contact(), Contact(),
		Contact(), Contact(),
		Contact(), Contact(),
		Contact(), Contact()
	};

};

# endif