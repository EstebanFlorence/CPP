#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

// int	main()
// {
// 	int		a[] = {1, 2, 3, 4, 5};
// 	double	b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
// 	const char*	c[] = {"Diego", "Armando", "Maradona"};

// 	std::cout << "Integer array:" << std::endl;
// 	::iter(a, sizeof(a) / sizeof(a[0]),  printType<int>);
// 	std::cout << std::endl;
// 	::iter(a, sizeof(a) / sizeof(a[0]),  power<int>);
// 	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
// 		std::cout << a[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "Double array:" << std::endl;
// 	::iter(b, sizeof(b) / sizeof(b[0]),  printType<double>);
// 	std::cout << std::endl;
// 	::iter(b, sizeof(b) / sizeof(b[0]),  power<double>);
// 	for (size_t i = 0; i < sizeof(b) / sizeof(b[0]); i++)
// 		std::cout << b[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "String array:" << std::endl;
// 	::iter(c, sizeof(c) / sizeof(c[0]), printType<const char*>);
// 	std::cout << std::endl;

// 	return 0;
// }
