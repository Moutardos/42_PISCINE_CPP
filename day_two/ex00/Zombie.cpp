#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	
	return ;
}

Zombie::Zombie(void) {

	return ;
}
Zombie::~Zombie(void) {

	std::cout << this->_name << " got destroyed" << std::endl;
}

void	Zombie::setName (std::string name) {

	this->_name = name;
}
void	Zombie::announce (void) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...";
	return ;
}

Zombie* newZombie (std::string name) {
	
	return (new Zombie(name));
}

void randomChump (std::string name) {

	Zombie	chump(name);

	chump.announce();
	return ;
}

Zombie* zombieHorde( int N, std::string name ) {

	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}