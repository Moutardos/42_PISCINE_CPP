#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::Serializer(Serializer &s) {

	s = *this;
}
Serializer::~Serializer(void) {}

Serializer	&Serializer::operator=(Serializer &c) {

	(void) c;
	return (*this);    
}

uintptr_t	Serializer::serialize	(Data* ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}