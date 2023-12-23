#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("oue");

	if (!zombie)
		return 1;
	zombie->announce();
	delete zombie;
	randomChump("test1");
	return 0;
}
