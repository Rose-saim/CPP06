#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Create class A" << std::endl;
			return ((Base *)new A);
		case 1:
			std::cout << "Create class B" << std::endl;
			return ((Base *)new B);
		case 2:
			std::cout << "Create class C" << std::endl;
			return ((Base *)new C);
		default :
			return (new Base);
	}
}
void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
 	}
  	catch (const std::exception&) 
	{
    	try 
		{
      	(void)dynamic_cast<B&>(p);
      	std::cout << "B" << std::endl;
    	}
		catch (const std::exception&) 
		{
      		try
			{
			(void)dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			}
			catch (const std::exception&) 
			{
				std::cout << "Base" << std::endl;
			}
  		}
	}
}	

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
			std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
			std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
			std::cout << "Class C" << std::endl;
	else
			std::cout << "It's no class" << std::endl;
}	



int main()
{
  Base* random_instance = generate();
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance);
  delete random_instance;
	return(0);
}