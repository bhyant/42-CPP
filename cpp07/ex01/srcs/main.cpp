#include "../iter.hpp"
#include <iostream>

void	doubleFloat(float &val)
{
	val *= 2.0f;
}

void	doubleInt(int &val)
{
	val *= 2;
}

int main(void)
{
	int intArray[] = {1 , 2, 3, 4, 5, 42};
	std::cout << "--- INT Test ---" << std::endl;
	iter(intArray, 6, print<int>);
	std::cout << std::endl;
	iter(intArray, 6, doubleInt);
	std::cout << std::endl;
	iter(intArray, 6, print<int>);

	std::cout << std::endl << "--- FLOAT Test ---" << std::endl;
	const float floatArray[] = {12.5f, 42.42f, 1337.42};
	iter(floatArray, 3, print<float>);
	std::cout << std::endl;
//	iter(floatArray, 3, doubleFloat);
	std::cout << std::endl;
	iter(floatArray, 3, print<float>);
	return 0;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   const int len = 5;

//   iter( tab, len, print<const int> );
//   iter( tab2, len, print<Awesome> );

//   return 0;
// }
