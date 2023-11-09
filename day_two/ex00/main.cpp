#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	Zombie *zombie = newZombie("oue");

	randomChump("test1");
	delete zombie;
	return 0;
}
