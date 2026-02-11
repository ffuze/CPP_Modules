#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <limits.h>
# include <stdint.h>

# include "Data.hpp"

class Serialization
{
	private:
		Serialization();
		~Serialization();
		Serialization(const Serialization& obj);
		Serialization& operator=(const Serialization& obj);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif