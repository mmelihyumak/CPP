#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer& source){
	*this = source;
}

Serializer& Serializer::operator=(const Serializer& source){
	(void)source;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data* Serializer::deserialize(uintptr_t raw){
	Data* result = reinterpret_cast<Data*>(raw);
	return result;
}