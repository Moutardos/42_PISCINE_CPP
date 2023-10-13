/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/13 18:50:16 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <iostream>

Class Phonebook {

public:
	Phonebook (void);
	~Phonebook (void);

private:
	Contact _contacts[8];

};

# endif