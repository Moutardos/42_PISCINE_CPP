#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*data2;
	uintptr_t	ptr;
	std::string	message;

	message =  "i love u\n";
	data.thing = reinterpret_cast<void *>(&message);
	std::cout << *reinterpret_cast<std::string *>(data.thing);
	ptr = Serializer::serialize(&data);
	data2 = Serializer::deserialize(ptr);
	std::cout << *reinterpret_cast<std::string *>(data2->thing);;
}