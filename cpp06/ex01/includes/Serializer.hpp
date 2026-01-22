#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <stdint.h>
#include <iostream>

typedef struct s_data
{
	int	value;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
