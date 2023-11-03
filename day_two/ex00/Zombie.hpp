#ifndef ZOMBIE
# define ZOMBIE

# include <iostream>

class Zombie {

public:
	Zombie	(std::string name);
	Zombie	(void);
	~Zombie	(void);

	static void	randomChump	(std::string name);
	static Zombie* zombieHorde( int N, std::string name );

	void	setName		(std::string name);
	void	announce 	(void);
	Zombie*	newZombie	(std::string name);

private:
	std::string _name;
};

#endif