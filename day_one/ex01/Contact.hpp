/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:03 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/13 18:27:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT

# include <iostream>

// Contact trust the user to give correct input and doesn't check it
class Contact {

	
public:
	Contact  (std::string fname, std::string lname, 
			std::string nname, std::string number, std::string secret);
	~Contact (void);
	std::string getFname     (void) const;
	std::string getLname     (void) const;
	std::string getNname     (void) const;
	std::string getNumber    (void) const;
	std::string getSecret    (void) const;
	void		changeNumber (std::string number);
	static bool	checkNumber  (std::string new_number) const;
	
private:
	std::string const _fname;
	std::string const _lname;
	std::string const _nname;
	std::string _number;
	std::string const _secret;

};

#endif