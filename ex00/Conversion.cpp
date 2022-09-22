#include "Conversion.hpp"

Conversion::Conversion(std::string string, char *parameter): string(string), parameter(parameter), verif(false), case_nb(2)
{
	std::cout << COLOR(CYAN, "Constructor default Conversion") << std::endl;
	Check(string);
}

Conversion::Conversion(Conversion const &copy)
{
	*this = copy;
}

Conversion::~Conversion()
{
	std::cout << COLOR(CYAN, "Destructor Conversion") << std::endl;
}

int	SearchChar(std::string string)
{
	std::string characters = "0123456789.f-";
	for (int i = 0; i < string.size() ; i++)
	{
		if (characters.find(string[i]) == std::string::npos)
		{
			return 0;
		}
	}
	return 1;
}


Conversion	&Conversion::operator=(Conversion const &copy)
{
	this->parameter = copy.parameter;
	this->num = copy.num;
	this->num_d = copy.num_d;
	this->num_f = copy.num_f;
	return(*this);
}

void	Conversion::Conversions()
{
	if (case_nb == 2)
		return ;
	num = ConvToInt(parameter);
	num_f = ConvToFloat(num);
	num_d = ConvToDouble(num);
	PrintConversions();
}


const char *Conversion::BadParameter::what()const throw()
{
	return("Argument is wrong");
}



void	Conversion::Check(std::string string)
{
	try
	{
		if (string == "nan" || string == "+inf" || string == "-inf")
		{
			case_nb = 0;
		}
		else if (string == "-" || string == "." || string == "f")
		{
			throw Conversion::BadParameter();
		}
		else if ((SearchChar(string)))
		{
			case_nb = 1;
		}
		else
			throw Conversion::BadParameter();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Conversion::PrintConversions()
{
	switch (case_nb)
	{
		case 0:
		{
			std::cout << COLOR(GREEN, "char: ") << COLOR(GREEN, "impossible") << std::endl;
			std::cout << COLOR(GREEN, "int: ") << COLOR(GREEN, "impossible") << std::endl;
			std::cout << COLOR(GREEN, "float: ") << COLOR(GREEN, string << "f") <<std::endl;
			std::cout << COLOR(GREEN, "double: ") << COLOR(GREEN, string) << std::endl;
		}
			break;
		case 1:
		{
			c = num;
			if (num > 32 && num < 127)
				std::cout << COLOR(GREEN, "char: ") << COLOR(GREEN, c) << std::endl;
			else
				std::cout << COLOR(GREEN, "char: ") << COLOR(GREEN, "Non displayable.") << std::endl;
			std::cout << COLOR(GREEN, "int: ") << COLOR(GREEN, this->num) << std::endl;
			std::cout << COLOR(GREEN, "float: ") << COLOR(GREEN, std::fixed) << COLOR(GREEN, std::setprecision(1)) << COLOR(GREEN, num_f) << COLOR(GREEN, "f") <<std::endl;
			std::cout << COLOR(GREEN, "double: ") << COLOR(GREEN, this->num_d) << std::endl;
		}
	}
}

int	Conversion::ConvToInt(std::string string)
{

	if (string == "nan" || string == "+inf" || string == "-inf")
		return (-1);
	this->num_d = stod(string);
	if (num_d < -2147483648)
	{
		std::cout << COLOR(YELLOW, "It's overflow, it changes to MIN_INT : -2147483648") << std::endl;
		return (-2147483648);
	}
	if (num_d > 2147483647)
	{
		std::cout << COLOR(YELLOW, "It's overflow, it changes to MAX_INT : 2147483647") << std::endl;
		return (2147483647);
	}
	this->num = stoi(string);
	return (num);
}

char	Conversion::ConvToChar(int num)
{
	if(!(num > 34 && num < 128))
	{
		this->c = num;
		return (0);
	}
		return (c);
}

float	Conversion::ConvToFloat(int num)
{
	int	size = string.size();
	num_f = stof(string);
	return (num_f);
}

double	Conversion::ConvToDouble(int num)
{
	num_d = stod(string);
	return (num_d);
}

// std::ostream &operator<<(std::ostream &os, Conversion const &element)
// {
// 	os << element.Getnum() << ": his Parameter is " << element.GetParameter() << std::endl;
// 	return (os);
// }
