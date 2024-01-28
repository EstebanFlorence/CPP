#include "Serializer.hpp"

int	main()
{
	Data*		dataPtr = new Data;
	uintptr_t	ptr = Serializer::serialize(dataPtr);

	std::cout << "Data pointer : " << dataPtr << std::endl;
	std::cout << "Serialized pointer : " << ptr << std::endl;
	std::cout << "Deserialized pointer : " << Serializer::deserialize(ptr) << std::endl;

	dataPtr->name = "DataName";
	dataPtr->data = 42;

	std::cout << "Name : " << dataPtr->name << std::endl;
	std::cout << "Data : " << dataPtr->data << std::endl;
	std::cout << "Name : " << Serializer::deserialize(Serializer::serialize(dataPtr))->name << std::endl;
	std::cout << "Data : " << Serializer::deserialize(Serializer::serialize(dataPtr))->data << std::endl;

	delete dataPtr;

	return 0;
}
