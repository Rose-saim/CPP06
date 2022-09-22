#include "Data.hpp"

int main()
{
	Data	test;
	test.ptr1 = "TEST";
	test.ptr2 = "NULL";
	test.value = 12;

	uintptr_t raw = serialize(&test);
	Data *end = deserialize(raw);
	std::cout << "Before: " << &test  << std::endl;
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "Deserialized: " << end << std::endl;
   	std::cout << "Last content: " << end->ptr1 << " " << end->ptr2 << " " << end->value	<< std::endl;
	return(0);
}