#include "templates.hpp"

int main( void ) {
    int a = 2;
    int b = 3;
    mySwap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::myMin( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::myMax( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    mySwap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::myMin( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::myMax( c, d ) << std::endl;
    return 0;
}