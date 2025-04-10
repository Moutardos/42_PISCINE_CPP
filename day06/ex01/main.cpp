#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*data2;
	uintptr_t	ptr;
	std::string	message;

	message =  "bonsoir paris\n";
	data.thing = reinterpret_cast<void *>(&message);
	std::cout << "Message stocked in data.thing" << std::endl;
	std::cout << *reinterpret_cast<std::string *>(data.thing);
	ptr = Serializer::serialize(&data);
	data2 = Serializer::deserialize(ptr);
	std::cout << "Message serialize in a uninptr_t and then deserialize into data2.thing" << std::endl;
	std::cout << *reinterpret_cast<std::string *>(data2->thing);;
}