#ifndef SCAVPTRAP_H
# define SCAVPTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap	(void);
	ScavTrap	(const ScavTrap &c);
	ScavTrap	(std::string name);
	~ScavTrap	(void);
	ScavTrap	&operator=	(const ScavTrap &c);
	
	virtual void	attack		(const std::string& target);
	void			guardGate	(void);

protected:
	static const std::string	_classType;

	bool	_gateKeep;

};

#endif