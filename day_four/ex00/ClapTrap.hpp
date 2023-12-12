#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

public:
	ClapTrap	(void);
	ClapTrap	(const ClapTrap &c);
	ClapTrap	(std::string name);
	~ClapTrap	(void);
	ClapTrap	&operator=	(const ClapTrap &c);

	unsigned int	getAD	(void) const;
	void			stats	(void) const;

	void	attack		(const std::string& target);
	void	takeDamage	(unsigned int amount);
	void	beRepaired (int amount);

private:
	std::string		_name;
	unsigned int	_HP;
	unsigned int	_EP;
	unsigned int	_AD;

};

#endif