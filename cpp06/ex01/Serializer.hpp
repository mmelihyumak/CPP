#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

struct Data{
	int m;
};

class Serializer{

	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer& source);
		Serializer& operator=(const Serializer& source);


		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif