#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate(void) {

	int res;

	srand(std::time(NULL));
	
	res = rand() % 3;
	switch (res)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void identify(Base *p) {

	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "pointer is of type A!" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "pointer is of type B!" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "pointer is of type C !" << std::endl;
	else
		std::cout << "couldn't convert pointer to any type" << std::endl;
}

void identify(Base &p) {

	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "pointer is of type A!" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "pointer is of type B!" << std::endl;
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "pointer is of type C !" << std::endl;
	else
		std::cout << "couldn't convert pointer to any type" << std::endl;
}
