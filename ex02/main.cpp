#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

Base *generate(int i)
{
	switch (i)
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
  std::cout << "===========-Value : 0-===========";
  Base* random_instance = generate(0);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance);
  delete random_instance;

  std::cout << "===========-Good Value : 1-===========";
Base* random_instance1 = generate(1);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance1);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance1);
  delete random_instance1;

  std::cout << "===========-Good Value : 2-===========";
  Base* random_instance2 = generate(2);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance2);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance2);
  delete random_instance2;

  std::cout << "===========-Good Value : 3-===========";
	Base* random_instance3 = generate(3);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance3);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance3);
  delete random_instance3;

  std::cout << "===========-Negatif Value : -1-===========";
  Base* random_instancen1 = generate(-1);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instancen1);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instancen1);
  delete random_instancen1;

  std::cout << "===========-Overload Value : 100-===========";
  Base* random_instance100 = generate(100);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance100);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance100);
  delete random_instance100;

  std::cout << "===========-Overload Value : 217483647-===========";
  Base* random_instanceopos = generate(2147483647);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instanceopos);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instanceopos);
  delete random_instanceopos;

  std::cout << "===========-Overload Value : -2147483648-===========";
  Base* random_instanceoneg = generate(-2147483648);
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instanceoneg);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instanceoneg);
  delete random_instanceoneg;
	return(0);
}