#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <iomanip>
# include <limits>
# include <stdint.h>
struct Data
{
	void *thing;
};

class Serializer {

public:
    static uintptr_t	serialize	(Data* ptr);
	static Data*		deserialize	(uintptr_t raw);

private:
	Serializer		(void);
	Serializer		(Serializer &s);
	~Serializer		(void);
	Serializer	&operator=			(Serializer &c);

};



#endif
