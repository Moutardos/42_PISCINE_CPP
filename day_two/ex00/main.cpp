#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	Zombie *zombie = newZombie("oue");

	if (!zombie)
		return 1;
	zombie->announce();
	delete zombie;
	randomChump("test1");
	return 0;
}
