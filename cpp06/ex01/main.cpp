#include "Serializer.hpp"

int main(){

	Data *data = new Data();
	data->m = 10;

	std::cout << data << std::endl;


	uintptr_t uintData = Serializer::serialize(data);
	std::cout << uintData << std::endl;

	Data *lastData = Serializer::deserialize(uintData);
	std::cout << lastData << std::endl;
	std::cout << lastData->m << std::endl;
	return 0;
}