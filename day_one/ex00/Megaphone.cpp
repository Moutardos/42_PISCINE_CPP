/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:10:48 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/30 13:53:31 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Megaphone {

public:
	Megaphone(char **sentence, int size);
	~Megaphone(void);
	void use(void) const;

private:
	char	**_sentences;
	int		_size;
};

Megaphone::Megaphone(char **sentences, int size) : _sentences(sentences), _size(size) {	return ; }

Megaphone::~Megaphone(void) { return ; }

void Megaphone::use(void) const{

	if (this->_size <= 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else 
	{
		for (int i = 0; i < this->_size ; i++) 
		{
			if (i > 0)
				std::cout << " ";
			std::string str = this->_sentences[i];
			for (std::string::iterator it = str.begin(); it != str.end(); it++)
				std::cout << char(std::toupper(*it));
		}
	}
	std::cout << std::endl;
	return ;
}

int	main(int argc, char **av) {

	Megaphone	megaphone(av + 1, argc - 1);
	megaphone.use();
	return 0;
}
