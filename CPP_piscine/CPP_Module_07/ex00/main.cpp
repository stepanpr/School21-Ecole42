
#include "whatever.hpp"

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2

int main( void ) 
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	//INT
	std::cout << std::endl << "-------test-INT-------" << std::endl;
	std::cout << "min( 77, 77 ) = " << ::min( 77, 77 ) << std::endl;
	std::cout << "max( 5, 7 ) = " << ::max( 5, 7 ) << std::endl;

	//FLOAT
	std::cout << std::endl << "-------test-FLOAT-----" << std::endl;
	std::cout << "min( 5.7f, 3.2f ) = " << ::min( 5.7f, 3.2f ) << std::endl;
	std::cout << "max( 1.5f, .7f ) = " << ::max( 1.5f, .7f ) << std::endl;

	//CHAR
	std::cout << std::endl << "-------test-CHAR------" << std::endl;
	std::cout << "min( '2', '7' ) = " << ::min( '2', '7' ) << std::endl;
	std::cout << "max( 'A', 'E' ) = " << ::max( 'A', 'E' ) << std::endl;

	//STRING
	std::cout << std::endl << "-------test-STRING----" << std::endl;
	std::cout << "min (\"str\", \"string\" ) = " <<  ::min(std::string("str"), std::string("string")) << std::endl;
	std::cout << "max (\"str\", \"string\" ) = " <<  ::max(std::string("str"), std::string("string")) << std::endl;

	//CLASS
	std::cout << std::endl << "-------test-AWESOME---" << std::endl;
	Awesome aw1(55);
	Awesome aw2(77);
	std::cout << "before swap: aw1 = " << aw1.getN() << ", aw2 = " << aw2.getN() << std::endl;
	swap(aw1, aw2);
	std::cout << "after swap:  aw1 =  " << aw1.getN() << ", aw2 =  " << aw2.getN() << std::endl;

	std::cout << "min( aw1, aw2 ) = " << ::min( aw1, aw2 ).getN() << std::endl;
	Awesome aw3 = ::max( aw1, aw2 ).getN();
	std::cout << "aw3 = max( aw1, aw2 ) = " << aw3.getN() << std::endl;

return 0;
}
