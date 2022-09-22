#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Not good numbers parameters." << std::endl;
		return (2);
	}
	std::string string = av[1];
	if (string.empty())
	{
		std::cout << "Parameter is empty" << std::endl;
		return (2);
	}
	Conversion conv(string, av[1]);
	conv.Conversions();
	return 0;
}