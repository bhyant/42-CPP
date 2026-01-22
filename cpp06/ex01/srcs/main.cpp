#include "../includes/Serializer.hpp"

int main(void)
{
	Data*	origin = new Data();

	origin->value = 42;
	std::cout << "Adress: " << origin << std::endl;
	std::cout << "Value: " << origin->value << std::endl;
	uintptr_t convert = Serializer::serialize(origin);
	std::cout << "Convert Value: " << convert << std::endl;
	Data* restore = Serializer::deserialize(convert);
	std::cout << "Adress: " << restore << std::endl;
	std::cout << "Value: " << restore->value << std::endl;
	delete origin;
	return 0;
}
