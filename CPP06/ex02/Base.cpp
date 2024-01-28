#include "Base.hpp"

Base::~Base() {}

Base*	generate()
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A" << std::endl;
			return new A();
		case 1:
			std::cout << "B" << std::endl;
			return new B();
		case 2:
			std::cout << "C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C identified" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << "A identified" << std::endl;
		static_cast<void>(a);
	}
	catch (const std::exception& ex) {}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << "B identified" << std::endl;
		static_cast<void>(b);
	}
	catch (const std::exception& ex) {}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << "C identified" << std::endl;
		static_cast<void>(c);
	}
	catch (const std::exception& ex) {}
}
