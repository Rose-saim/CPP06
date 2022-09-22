#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>
#include <iomanip>
#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#define RST  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define COLOR(C, c) C << c << RESET

class Conversion
{
	private:
		bool verif;
		char *parameter;
		std::string string;
		char c;
		int num;
		int case_nb;
		float num_f;
		double num_d;
	public:
		Conversion(std::string string, char *parameter);
		Conversion(Conversion const &copy);
		virtual ~Conversion();
		void	Check(std::string string);
		Conversion &operator=(Conversion const &copy);
		std::string	GetName()const;
		int	GetGrade()const;
		void	Conversions();
		void	PrintConversions();
		int		ConvToInt(std::string string);
		char	ConvToChar(int num);
		float	ConvToFloat(int num);
		double	ConvToDouble(int num);
		class BadParameter: public std::exception
		{
		public:
			virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream os, Conversion const &element);

#endif